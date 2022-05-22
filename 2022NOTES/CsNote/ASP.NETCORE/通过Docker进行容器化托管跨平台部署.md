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

`docker prune -a`清空镜像 （悬空，包括容器）

`docker rm $(docker ps -a -q)`删除所有停止的容器（实例）

`docker rmi $(docker images -q)`删除所有镜像

vs下载docker扩展





Docker  image镜像  容器   仓库（一个registry 下有多个仓库，一个仓库有多个标签）<仓库名>:<标签>给出对应的镜像

**Dockerfile是什么**

Dockerfile是一个创建镜像所有命令的文本文件, 包含了一条条指令和说明, 每条指令构建一层, 通过docker build命令,根据Dockerfile的内容构建镜像,因此每一条指令的内容, 就是描述该层如何构建.有了Dockefile, 就可以制定自己的docker镜像规则,只需要在Dockerfile上添加或者修改指令, 就可生成docker 镜像。

简单地dockerfile文件

```dockerfile
FROM nginx
RUN echo '<h1>It works!</h1>' > /usr/share/nginx/html/index.html
```



我们的web项目要想运行，需要有一个像IIS一种的服务器组件，在linux里我们一般使用jexus来实现这个功能，也就是说，我们的docker镜像应该即有mono还要有jexus的集成，这个镜像我们可以自己写，也可以使用现成的镜像`azraelrabbit/monupw`

`docker pull azraelrabbit/monupw`



**部署的步骤**

1. 建立Dockerfile文件，发布网站时应该带上
2. 发布网站
3. 进行发布后的地址
4. 打包 docker build . -t 镜像名称
5. 启动容器 docker run -d -p 8080:80 镜像名称





--------------------------------

文件发布方式

```dockerfile
FROM mcr.microsoft.com/dotnet/aspnet:3.1 AS base
EXPOSE 80
WORKDIR /muxuedotapi
COPY . /muxuedotapi
ENTRYPOINT ["dotnet", "testweb.dll"]
```

自动生成

```dockerfile
#See https://aka.ms/containerfastmode to understand how Visual Studio uses this Dockerfile to build your images for faster debugging.

FROM mcr.microsoft.com/dotnet/aspnet:3.1 AS base
WORKDIR /app
EXPOSE 80

FROM mcr.microsoft.com/dotnet/sdk:3.1 AS build
WORKDIR /src
COPY ["testweb/testweb.csproj", "testweb/"]
RUN dotnet restore "testweb/testweb.csproj"
COPY . .
WORKDIR "/src/testweb"
RUN dotnet build "testweb.csproj" -c Release -o /app/build

FROM build AS publish
RUN dotnet publish "testweb.csproj" -c Release -o /app/publish

FROM base AS final
WORKDIR /app
COPY --from=publish /app/publish .
ENTRYPOINT ["dotnet", "testweb.dll"]
```

构建镜像



要注意进入项目目录,dockerfile 也在其中

`docker build -t  mydockertest.`后面有点号,小写

Error parsing reference: "mcr.microsoft.com/dotnet/aspnet:3.1 AS base" is not a valid repository/tag: invalid reference format

可能是Docker版本问题

`yum remove docker docker-common container-selinux docker-selinux docker-engine`删除

`yum update`更新yum

3、安装 yum-utils
 yum install -y yum-utils
4、添加yum源
yum-config-manager --add-repo http://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo
5、安装docker-ce
yum install -y docker-ce







运行镜像（容器就像镜像的实例）

```dockerfile
docker run -d -p 8083:80 --name dotapicontainer2(容器) dotapidockertest(image)
```

`c21be51e892fae0556072c8dbbaacd1ca5478731bb6fe283dfd6255cebe8aa82`运行成功

![image-20220517193821401](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220517193821401.png)

![image-20220517201812612](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220517201812612.png)







```
 <environmentVariables>
        <environmentVariable name="ASPNETCORE_ENVIRONMENT" value="Production" />
      </environmentVariables>
    </aspNetCore>
```









#### 改正

```dockerfile
#See https://aka.ms/containerfastmode to understand how Visual Studio uses this Dockerfile to build your images for faster debugging.
//采用vs自动生成的，但是要改一些东西
FROM mcr.microsoft.com/dotnet/aspnet:3.1 AS base
WORKDIR /app
EXPOSE 80

FROM mcr.microsoft.com/dotnet/sdk:3.1 AS build
WORKDIR /src
COPY ["./testweb.csproj", "testweb/"] #testweb改成了点号，bug。。
RUN dotnet restore "testweb/testweb.csproj"
COPY . testweb/  #反过来将点号改为testweb/
WORKDIR "/src/testweb"
RUN dotnet build "testweb.csproj" -c Release -o /app/build

FROM build AS publish
RUN dotnet publish "testweb.csproj" -c Release -o /app/publish

FROM base AS final
WORKDIR /app
COPY --from=publish /app/publish .
ENTRYPOINT ["dotnet", "testweb.dll"]
```

```dockerfile
FROM mcr.microsoft.com/dotnet/aspnet:3.1 
FROM mcr.microsoft.com/dotnet/sdk:3.1
EXPOSE 80
WORKDIR /app
COPY . /app
ENTRYPOINT ["dotnet", "testweb.dll"]
```

