# MCInjector
- 大部分代码来自 [FateInjector](https://github.com/fligger/FateInjector)
- Most of the code comes from [FateInjector](https://github.com/fligger/FateInjector)

## 简介

MCInjector 是一个用于注入 DLL 到指定进程的工具。适用于[BetterBedrockLauncher](https://github.com/Chlna6666/BetterBedrockLauncherCore)



## 使用方式

### 1. 命令行参数

在命令行中运行 MCInjector，可以使用以下参数：

- `-p <file_directory>`: 指定要注入的 DLL 文件路径。
- `-i <procId>`: 指定目标进程的进程ID或进程名。

### 2. 示例

#### 示例 1: 注入到指定进程ID

```bash
MCInjector.exe -p "M:/xxx/xxx.dll" -i 14514
```
#### 示例 2: 注入到指定进程名
```bash
MCInjector.exe -p "M:/xxx/xxx.dll" -i Minecraft.Windows.exe
```
