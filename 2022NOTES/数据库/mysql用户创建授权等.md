##### `mysql`用户创建授权等

* 用户增删改查

  * `create user 'username'@'localhost(ip)' identified by 'password'`;

    （猜想由于指定了localhost所以默认上面的数据库都能访问）

  * `drop user 'zlc'@'localhost'`删除用户
  * `drop user 'db_owner'@'%'`没有指定localhost 就默认为%
  * `select user from mysql.user`用来查询用户

* 授权

  * 查看权限

    `show grants for db_owner`

  * 单个privilege授权

    `grant select on table student to 'username‘ with grant option;`

  * 角色授权

    `create role r1`

    `grant select (privileges) on table student to r1`

    `grant role r1 to 'username'` with admin option;在授权的过程发现如果`zlc@localhost`会发生报错，`@’%’`就没有问题，有可能是因为 r1 默认是`@'%'`刷新授权`flush privilege`

    * 激活角色

      [(20条消息) MySQL8.0的用户创建&用户权限授予&角色创建&角色授权给用户等问题总结（本人被坑怕了＜-_＜-）_@Mrxu的博客-CSDN博客_没有角色能给用户授予权限吗?](https://blog.csdn.net/qq_44323019/article/details/109550171)

  * 收回授权

    * 收回角色的权限

      `revoke select,insert on table student on r1`

    * 收回用户的授权

      `revoke select(sno) on table student from 'zlc'`

      关键字public代表所有用户

      加入u1授权了u2,u3,当u1权限被撤销，那么株连。

      貌似一次只能对一个表的多个功能进行授权和撤销

* [MySQL用户权限验证与管理方法详解_Mysql_脚本之家 (jb51.net)](https://www.jb51.net/article/139101.htm)

