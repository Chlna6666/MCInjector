#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "pch.h"
#include "inject.h"
#include <TlHelp32.h>

DWORD procId = 0;

DWORD GetProcessIdFromArgument(const std::string& argument) {
    if (std::all_of(argument.begin(), argument.end(), std::isdigit)) {
        return std::stoi(argument);
    }


    const std::wstring processName(argument.begin(), argument.end());
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnap == INVALID_HANDLE_VALUE) {
        return 0; 
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hSnap, &pe32)) {
        do {
            if (processName == pe32.szExeFile) {
                CloseHandle(hSnap);
                return pe32.th32ProcessID;
            }
        } while (Process32Next(hSnap, &pe32));
    }

    CloseHandle(hSnap);
    return 0; 
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << "Usage: -p <file_directory> -i <procId/exe>" << std::endl;
        return 0;
    }

    std::string command = argv[1];

    if (command == "-p") {
        std::string fileDirectory = argv[2];
        std::wstring StrPath(fileDirectory.begin(), fileDirectory.end());

        DWORD InjectTarget = GetProcessIdFromArgument(argv[4]);

        if (InjectTarget == 0) {
            std::cout << "Invalid process ID or process name." << std::endl;
            return 0;
        }

        performInjection(InjectTarget, StrPath.c_str());

        
        std::cout << "File directory: " << StrPath.c_str() << std::endl;
        std::cout << "procId: " << InjectTarget << std::endl;
    }
    else {
        std::cout << "Usage: -p <file_directory> -i <procId/exe>" << std::endl;
    }

    return 0;
}
