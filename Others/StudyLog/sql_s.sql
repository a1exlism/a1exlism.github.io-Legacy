
-------------------------sql----------------------------------------------------------------------------------------
ER图:
 用矩形表示实体型，矩形框内写明实体名；
 用椭圆表示实体的属性，并用无向边将其与相应的实体型连接起来；
 用菱形表示实体型之间的联系，在菱形框内写明联系名，并用无向边分别与有关实体型连接起来
 同时在无向边旁标上联系的类型（1:1,1:n或m:n）。

简化:
	对象 		矩形
	属性 		椭圆
	行为(函数) 	菱形

mysql -h 主机名 -u 用户名 -p

-h : 该命令用于指定客户端所要登录的MySQL主机名, 登录当前机器该参数可以省略;
命令需要打;之后才能执行
show databases;
先使用某一个数据库 例如:use world;
之后可以查看表		show tables;
select user();	去的当前登录用户	等同于问mysql"who am i"
select database();	当前使用的数据库
select current_date/time/now();	当前日期/时间/完整时间
version();

总结:select之后直接加上某个名字 一般是查询当前该名字的信息内容
 	
http://images.cnitblog.com/blog/453818/201305/09030127-13657abaf11945d1916297e6d23f2ec9.png
以上网址可以知道到底什么是键值 Key	表头header 


insert [into] 表名 [(列名1, 列名2, 列名3, ...)] values (值1, 值2, 值3, ...); //[]中的内容可选
insert into students (name, sex, age) values("孙丽华", "女", 21);

update 表名称 set 列名称=新值 where 更新条件;
delete % from 表名称 where 删除条件;
alter table 表名 add 列名 列数据类型 [after 插入位置];
alter table 表名 drop 列名称; 删除列
alter语句 更改
Alter table tb add primary key(id);  创建主键//在已有表的情况下
Alter table tb change id id int(10) not null auto_increment=1; //自增
PRIMARY KEY (Id_P)  //创建之初
alter table register rename to a_register; //更改表名
