#### 装 linux双系统

###### 一、 准备工作

* 1.准备工作
      ①准备 4g ubuntu 启动盘
      ②此电脑-> 管理 ->磁盘管理 ->  efi 系统分区，点击下方磁盘0属性->卷
      发现是第一种搭配 uefi +gpt(bios +mbr)
      ③关快速启动（windows）   √
       控制面板\硬件和声音\电源选项 ->选择电源按钮功能->更改当前不可用设置->取消勾选 
       ④关闭安全启动（bios,attention to not write）
       打开电脑 BIOS 菜单：

        通常可在电脑启动期间按某个键（如 F1、F2、F12 或 Esc）来访问此菜单。

  或    
        secure boot  选项 enable to disable

        在 Windows 中，选择“重启”时按住 Shift。 转到“故障排除”“高级选项: UEFI 固件设置”。
         。。。。待补充

​              ⑤关闭intel rst (快速存储)

​        

```
1.以管理员身份打开cmd，不是那个普通的cmd哈。
2.输入bcdedit /set safeboot minimal回车
3.Restart the computer and enter BIOS Setup
4.Change the SATA Operation mode to AHCI from either IDE or RAID
5.Save changes and exit Setup and Windows will automatically boot to Safe Mode.
6.以管理员身份打开cmd，不是那个普通的cmd哈。
7.bcdedit /deletevalue safeboot回车
8.Reboot once more and Windows will automatically start with AHCI drivers enabled.
9.恢复正常了，正常使用Windows。
————————————————
版权声明：本文为CSDN博主「音程」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_43391414/article/details/120606567



联想f12
```

[(保姆式教学) Win10 + Ubuntu 20.04——双系统安装方法 + 配置显卡 + root权限 + flash调配_强秦的沉默烤羊的博客-CSDN博客_ubuntu系统](https://blog.csdn.net/codeHonghu/article/details/111940656)

⑥关闭bitlockers

设置搜索bitlockers

to be continued
