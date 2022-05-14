#### 通过Docker进行容器化托管跨平台部署

##### 配置.Net Core 应用的开发调试环境(centos7)

1.下载docker

`yum install docker`

`docker version` 	1.13.1

2.基本命令

`service docker start`启动

`systemctl enable docker`设置开机启动docker

`systemctl stop docker`停止docker

`docker search tomcat`搜索docker镜像（例如tomcat)

`docker pull tomcat`拉取

`docker rmi 镜像id`删除

`docker image ls`查看镜像

`docker ps -a`查看所有容器

`docker start 容器id`启动容器

`docker stop 容器id`停止

`docker rm 容器id`删除

vs下载docker扩展