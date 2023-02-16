### 介绍

基于putty官方源码，添加时间戳，并通过mtputty管理多标签。

### 使用
1、获取putty软件

方式1：直接下载已编译好的最新release版本软件，下载地址 https://github.com/cjpthree/puttyPlus/releases/

方式2：用vs2019打开putty-src-0.78-windows文件夹，点击"生成"--"全部生成"编译，找到生成的putty.exe文件。

2、打开多标签页管理工具mtputty

3、配置putty软件的路径

点击"Tools"--"PuTTY location"，配置putty.exe的路径。

![image](https://user-images.githubusercontent.com/7747428/158564236-968e46a1-29e9-496b-8014-d3f2d9080d00.png)

4、添加server

点击"Server"--"Add server..."填写server配置。

<img src="https://user-images.githubusercontent.com/7747428/126021422-f237a6c3-7714-48c7-8a46-4dc5b9fc7438.png" height="70%" width="70%" />

5、打开server

<img src="https://user-images.githubusercontent.com/7747428/126021532-41004469-1570-48bb-9bac-7614105666e7.png" height="70%" width="70%" />

6、设置保存日志

如果需要保存日志，如下设置：

点击"Run PuTTY Config"，导航到"Session"--"Logging"--"Session logging:"，选中"Printable output"，日志文件名字设置为"putty-&H-&Y&M&D-&T.log"。导航到"Session"，选中"Default Settings"，点击"Save"。

<img src="https://user-images.githubusercontent.com/7747428/196185760-86c5366b-8f6a-4865-a466-9ec4fba87c9f.png" height="70%" width="70%" />

### FAQ
https://github.com/cjpthree/puttyPlus/wiki/FAQ






