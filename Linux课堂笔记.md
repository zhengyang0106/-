#             Linux   课堂笔记



- **链接树莓派**

  - ssh    用户名@树莓派地址

- **链接其他电脑**

  - ssh 用户名 @电脑地址

- **scp命令**

  - 本地上传文件
    - scp  文件路径   zhengyang@树莓派地址：树莓派路径地址
  - 从远端下载文件 或 文件夹
    - scp   zhengyang@树莓派地址：树莓派路径   本地路径    
    - scp -r    下载文件夹  -r  是递归
    - scp - 3   是使用一个中转服务器  具体使用方式  tldr  scp
    - scp -i  使用私钥验证远程登录

- **创建文件夹** 

  + mkdir  文件夹名子

- **删除文件夹及内容**

  + rm -rf   r为递归 f为不提醒

- **打开查看公钥 **

  + cd ~/.ssh   cat id_rsa.pub

- **加密方式**

  + 对称加密
  + 非对称加密 --->rsa  ---> 基于 超大整数因数分解     分解难  解密越难   
  + 信息摘要

- **免密登录**

  + ssh -keygen    --->生成秘钥
  + tssh - copy -id  ~/.ssh/id_rsa.pub   --->把秘钥复制到 树莓派

  + ![免密链接](/home/zhengyang/图片/免密链接.png)

- **编译文件  成一个可执行文件**

  + gcc tcp.c -o  check  --->把 tcp.c   编译成一个 可执行文件  check
  + mv check  /usr/bin      把check 把放到  PATH的路径下  使得 在任何目录下都可一执行 check 命令

- **github的免密链接 并 上传文件**

  + 先把主机公钥放到 github上面
  + github 建库 并执行远程连接
    + git remote add origin git@github.com:zhengyang0106/Euler.git
    + git add *  --->追踪要上传文件  * 代表全部文件
    + git commit -m "备注"---> 上传  并  设置备注信息
    + git push -u origin master   --->记得第一次 用    -u  以后不用
    + git pull origin master  

  + 检查远程连接情况
    + git remote -v
  + 断开远程连接
    + git remote  remove origin --->把已建立的远程链接 断开

- **目录**

  + ./   -->当前目录
  + ../  --> 父目录  
  + .apt   --->以   .   开头的文件为隐藏文件

- **赋予权限**

  + chmod a+x 文件名   ---> 赋予文件 可执行权限  a 代表全部文件   +x 代表可执行

- **echo的用法**c

  + echo $PATH  查看PATH下的路径
  + echo -n 不输出最后的换行符
  + echo -e 对转义符进行转义
  + echo-E不对不对转义符进行转义
  + \c 转义符  --->不输出最后的 \n  并且\c 之后的也不在输出  echo  输出时  自动换行
  + echo   默认不对转义符 进行转义
  + echo  "  ...   "  > test     把内容输入到 文件test中
  + echo “...”  > /dev/null   把内容输出到  /dev/null --->如同系统垃圾箱  
  + 

- **PATH**

  + 文件放到PATH的路径下  在什么目录下都可以执行   eg： pwd   ls  在任何目录下都可以执行 他们这些命令脚本全部放在了 PATH 下的某个路径    

- main() 函数的三个参数   

  - 参数个数
  - 参数字符串
  - 环境变量

- **tldr 命令**

  - tldr scp   --->查看scp的使用方法

- **VIM**

  - 百度 ma6174  github  上面有简单的安装步骤
  - vimrc 文件是  vim的配置资源  可修改 vim给出的初始信息

- **管理员权限**

  - sudo  - i   进入管理员权限 
  - sudo   ！！  用于执行上一条没有权限的命令 
  - \#代表管理员权限下   \$  表示普通用户权限下
  - ctrl + d   or    logout  退出超管模式
  -  su - zy --->进入到普通用户家目录下  
  - su  zy  ---->进入到超管模式下的家目录

- **错误信息**

  - permission denied
    - 管理员权限下的文件
    - 没有可执行权限的文件
  - E  or  error  ：错误信息的说明
  - fatal  致命类型错误

- **apt - get **

  - apt -get upgrade --->  更新版本
  - apt -get update  --->更新源信息
  - apt -get install a ---- >安装软件a
  - apt -get remove a ---> 卸载a
  - apt -get - -purge remove a   ----> 完全卸载a   （把软件的配置信息用户信息一起删除）
  - apt -cache  search    a   查找a 的软件
  - apt-get  install -f   自动安装
  - apt -get authoremove   删除自动安装的包

- **scppi  and  sshpi**

  + scppi --->非局域网下的  scp功能    scppi为已经安装好的脚本文件
  + sshpi  --->非局域网下  链接树莓派   实现方法如同  树莓派链接到一个公网服务器  用户也可以连接到  如同scp -3 的功能实现

- **#include<unistd.h>**

  + gethostname(haostnanme,sizeof(hostname))   ---->   此函数用于获取主机名 
  + getcwd(pwd , sizeof(pwd))  ---->此函数用于获取路径
  + getuid()  ---> 获取ID号

- **#include <pwd.h>**

  + getpwuid(id 号) -->查看passwd数据查看用户名

    + struct passwd *pwd;

      pwd =getpwuid(getuid());

      pwd->pw_name;    #调用成员

  + struct passwd

    {

    char *pw_name;           #用户登录名     

      char *pw_passwd;           #密码  （加密后） 

      uid_t pw_uid;              #用户ID 

      __gid_t pw_gid;              #组 ID 

      char *pw_gecos;             #详细用户名  

      char *pw_dir;                #用户目录 

      char *pw_shell;               # shell 程序名

    };

    

- **which **  

  + 用于查找命令文件　依次　从ＰＡＴＨ　往下查找　　找到就停止  

- **file**

  + 查找文件　查看文件的基本信息

- **linux**下有７种文件

  1.   \-   regular file 普通文件
  2.   d  directory  目录
  3.   l   link 　　链接
  4.   b  block   块设备　　存储数据以供系统存取接口设备－硬盘
  5.   c  character   字符设备　　串口设备，键盘鼠标等
  6.   s   socket     套接字
  7.   p   pipe      管道  

- **>  重定向**

  1.每个进程都会在内部打开三个文件

  + stdin  -- 标准输入文件  0 代表
  + stdout  -- 标准输出文件  1 代表
  + stderror  -- 标准错误输出文件  2 代表

  2.  echo     1>  a   2>&1   --把1从定向到a里面  2重定向到1里面  1 or 2和> 没哟空格  记住格式
  3. echo $?  上一命令返回值 

+ **权限 **
  + chmod  ---修改权限 
    + u  用户
    + g  组
    + o  其他人
    + 增减权限  u or g or o  + / -    r/w/x   a + 权限 代表全体增加
    + 默认权限 755
  + chown   --- 修改文件所属人
    + chown   owner ：group   file  带着： 可以一起修改去o 和 g 的所属
  + chgrp  --- 修改组权限
  + 三种用户 权限
    1. 超级管理员  ---无所不能 ，不受权限约束
    2. 管理员  --  普通用户 使用 su - 可以切换
    3. 普通用户

+ **whoami  和 who am i区别**
  + whoami 我的当前身份
  + who am i  真实身份  比如zhengyang 使用su-i切换到管理员  但是真实身份是zhengyang

+ **如果使用 *cat* 读取为乱码  可以使用 *last*  尝试**

+ **man 手册**

  + man -f  command    精确查找 command
  + man -k  command   模糊匹配  查找command
  + man  和  tldr  tldr需要联网查询

+ **bash 通配符**
  + ?    -- 代表单个任意字符
  + \*  --- 代表任意多个字符
  + [list]   --- 匹配任意一个 list 中字符
  + [!list]
  + {str1,str2, ...}  -- 匹配任意一个字符串str

+ **命令 + &**   -- 后台执行 
  + jobs  查看挂起命令
  + pkill   结束命令   前后台  都可以  但是此命令较为危险  注意是模糊匹配  一定确定好命令名字
  + crtl +z  挂起
  + fg  --- 调到前台
  + bg  --- 调到后台

+ **&&和 ||**  -- 和c语言类似

+ \`    \`    命令替换符  优先执行

+ **管道和重定向**

  + \>   重定向符  
  + \>\>   追加符  
  + <    把文件内容重定向到命令后面 作为参数
  + <<     定义结束符

+ 转义符

  + ‘ 硬转义’    里面的字符都作为普通 字符, 一般不允许在里面出现 ’ 号 

  + “软转义”   转义字符（$ ` \）依然好用 eg \n 换行

  + \a  响铃

    \r  回车

    \t  水平制表符

    \v  垂直制表符

    \0  空字符

+ **shell 元字符**

  + **=  **为变量赋值  中间不要空格

  + **\` \`**   命令替换符   先执行

  + **$    **变量替换符  注意用{} 避免混淆  $0  --$9 ... 代表文件的参数

    $0  ---当前程序名 脚本名  命令名

    $1 -...  表示第几个参数

    $()  ---同 `` 命令替换符

    $[]   --**整数**的计算  a= 12 b=13  $[ $a+$b ]  **注意空格** 还有里面的变量也最好用$标识 

    ${}    限定变量名范围

  + | 管道命令   只接受 stdout  **不接受 错误输出**

  + & 后台运行

  + （） 在子进程中运行

  + {}  当前Shell中执行命令

  + \[  ]  通配符  匹配一个字符  { } 可以匹配字符窜

  + ；命令结束符

  + &&  or  ||

  + !   执行 history 中的 某一命令  !2001   或者 你最近的一个命令  !su  可能会执行之前的su -i

  + % 1  === fg 1

  + ^   取非  与 ！ 雷同   ^str 1^str2^   将上一个str1 替换为str2

  + ~  家目录

  + \#   注释

  + \*   通配符   任意字符

  + ？  统配符  任一字符

  + .    当前目录   source意思

  + \-     减号  上次工作目录  eg  cd -   回到上次目录

  + :  真值 

  + /  目录分隔符

+ **目录结构**

  + usr    用户级别的软件存放
  + boot   启动项、
  + dev   设备文件  键盘鼠标
  + etc   全局配置文件/软件  只能管理员管理
  + home   用户的家目录存放处
  + media   媒体 u盘光盘 
  + mnt       默认挂载点  没有桌面系统的都挂在这
  + opt      可选项 一般没什么用
  + bin     可执行程序
  + sbin   同bin
  + tmp   临时文件夹  默认 777权限 文件  但是只能自己可以删除
  + var  动态数据  例如 log系统日志  和 软件日志

+ **基本系统**

  + BIOS 固件 在cmos 上的只读软件

    1.进行硬件检测

    2.读取并执行第一个启动设备的MBR(主引导记录  存储在磁盘上 )的bootloader

    3.加载kernel  开始检测硬件  

    4.加载虚拟文件系统 并加载启动所需内核模块

    5.启动第一个进程init

    6.init启动getty

    7.运行 x windows

+ **运行级别**  --7种

  | run level | 含义                    | 描述                                              |
  | --------- | ----------------------- | ------------------------------------------------- |
  | 0         | halt                    | 系统关机  init 0                                  |
  | 1         | single user mode        | 单用户模式 系统维护时用                           |
  | 2         | multi-user, without nfs | 多用户模式  纯文本模式 不包含 NFS（网络文件系统） |
  | 3         | full multi-user  mode   | 完整的多用户纯文本模式                            |
  | 4         | unused                  | 系统保留                                          |
  | 5         | x11                     | 在 run level 3 基础上加载 X Windows               |
  | 6         | reboot                  | 重启                                              |

+ **配置文件**

  | 系统文件      | 含义                 |
  | ------------- | -------------------- |
  | /etc/inittab  | 运行级别 控制台数量  |
  | /etc/timezone | 时区                 |
  | **文件系统**  |                      |
  | /etc/fastab   | 开机时挂载的文件系统 |
  | /etc/mtab     | 当前挂载的文件系统   |
  | **用户系统**  |                      |
  | /etc/passwd   | 用户信息             |
  | /etc/shadow   | 用户密码             |
  | /etc/sudoers  | 用户列表             |

  | /etc/group         | 用户组信息                   |
  | ------------------ | ---------------------------- |
  | /etc/gshadow       | 用户群组密码                 |
  | **Shell**          |                              |
  | /etc/shells        | 可用Shell列表                |
  | /etc/profile       | 用户首选项（默认的配置选项） |
  | /etc/bashrc        | bash  配置文件               |
  | **系统环境**       |                              |
  | /etc/updatedb.conf | 文件检索数据库配置信息       |
  | /etc/issue         | 发行信息                     |
  |                    |                              |

  | 网络                    | vim                |
  | ----------------------- | ------------------ |
  | /etc/iftab              | 网卡MAC地址绑定    |
  | /etc/hosts              | 主机列表           |
  | /etc/hostname           | 主机名             |
  | /etc/resolve.conf       | 域名解析服务器地址 |
  | /etc/network/interfaces | 网卡配置文件       |

  | 用户配置文件  |                  |
  | ------------- | ---------------- |
  | .bash_rc      | bash 的配置文件  |
  | .bash_profile | bash的首登录文件 |
  | .bash_logout  | bash 的退出文件  |

+ **系统信息**

  | 命令   | 功能                                 |
  | ------ | ------------------------------------ |
  | uptime | 打印开机时长和平均负载               |
  | w      | 当前登录用户的列表级执行任务         |
  | who    | 当前登录系统的用户信息               |
  | whoami | 打印当前有效用户名称                 |
  | last   | 显示用户最近登录信息                 |
  | uname  | 打印系统信息                         |
  | data   | 显示或设置系统时间c                  |
  | cal    | 显示日历                             |
  | id     | 查看用户详细信息  包括 uid gid grous |

  tty  --终端

  IDLE  --- 空闲时间

  pcpu  ---当前进程占用时间

  JCPU  ---  和该终端相连的所有进程占用的时间包含当前正在执行的后台做业务

  

  

  | uptime                    | phsv                         |
  | ------------------------- | ---------------------------- |
  | p                         | 可读性更好                   |
  | s                         | 开机时间                     |
  | **w**   【husfv】《user》 | **hsf**                      |
  | h                         | 打印头信息                   |
  | s                         | 使用短输出格式               |
  | **who**                   | **Huq**                      |
  | q                         | 只显示登录用户名称和人数总和 |
  | H                         | 显示各栏的标题信息           |
  | who am i   ==  logname    | 登录用户名                   |

  | last 【fnx】《user..》《tty》 | fnx                                          |
  | ----------------------------- | -------------------------------------------- |
  | f                             | 指定记录文件                                 |
  | n                             | 指定输出记录数                               |
  | x                             | 显示系统关机 重新关机等信息                  |
  | 存在路径                      | last 在 、var/log下                          |
  | 数据文件                      | 由特殊编码格式编写的文件  只能由特殊工具打开 |
  | **uame**                      | **amnvpio**                                  |
  | a                             | 全部信息                                     |
  | m                             | 电脑类型                                     |
  | n                             | 主机名                                       |

  | v        | os版本                 |
  | -------- | ---------------------- |
  | p        | 处理器类型             |
  | i        | 硬件平台               |
  | o        | 操作系统名称           |
  | **date** |                        |
  | +“%s”    | 计算机元年到今天的秒数 |
  | +“%S”    | 当前秒                 |
  | h        | 英文月                 |
  | H        | 当前小时               |
  | d        | 当前天                 |

  | D                            | 05/07/19格式输出 |
  | ---------------------------- | ---------------- |
  | m                            | 数字月           |
  | y                            | 年19             |
  | Y                            | 2019             |
  | M                            | 分钟             |
  | date -d  “100 years ago”     | 100年前          |
  | date -d  “ now + 10 minutes“ | 十分钟后         |
  | -s                           | 设置时间         |

  

| pwd       | 功能               |
| --------- | ------------------ |
| L         | 逻辑工作目录       |
| P         | 物理工作目录       |
| **mkdir** |                    |
| -m        | 赋值权限           |
| -p        | 自动创建父目录     |
| **rmdir** |                    |
| -p        | 会把空的祖先都删去 |
| -f        | 不论是否空  都删除 |
|           |                    |

| cp     | 功能                                   |
| ------ | -------------------------------------- |
| i      | 人机互动                               |
| p      | 连同属性一起拷贝                       |
| d      | 若文件有链接属性，则复制链接文件的属性 |
| s      | 拷贝为软连接                           |
| l      | 拷贝为硬链接                           |
| u      | 源文件比目的文件更新才拷贝             |
| **rm** |                                        |
| f      | 强制删除                               |

| mv           | 功能               |
| ------------ | ------------------ |
| i            | 互动               |
| f            | 强制               |
| u            | 源文件更新才会移动 |
| **basename** | 文件名             |
| **dirname**  | 所在文件夹名字     |
| **cat**      | 正向连续读         |
| v            | 列出看不出的字符   |
| E            | 断行符  显示为 $   |
| T            | TAB  显示为^I      |

| A        | vET集合                       |
| -------- | ----------------------------- |
| b        | 列出行号 空行不编号           |
| n        | 空行也编号                    |
| **tac**  | 反向读                        |
| nl       | 输出行号显示文件              |
| nl -b a  | cat -n                        |
| nl -b t  | cat -b                        |
| nl -n ln | 行号在屏幕最左边              |
| nl -n rn | 行号在自己字段最右边          |
| nl -n rz | 行号在自己字段最右边 前面补零 |

| w 《num》     | 行号占位数             |
| ------------- | ---------------------- |
| **more**      | 查看文件               |
| **less**      | 可以上下翻页           |
| less 中 n     | 乡下查找               |
| ...         N | 查找上一个             |
| /？           | 反向查找               |
| f             | 显示当前文件名称和行数 |
| **head**      | 查看头10 行            |
| - n   num     | 显示前 num行           |
| -n   -num     | 不要后 num行           |



| tail                      | 看后10 行           |
| ------------------------- | ------------------- |
| -n num                    | 看 后num行          |
| -n +num                   | 不看后 num行        |
| **od**                    | 查看二进制文件      |
| **mtime**                 | 内容修改 会变更时间 |
| **ctime**                 | 权限修改变更时间    |
| **atime**                 | 打开过就会变更      |
| ls -l  --time=ctime  file | 看权限修改时间      |
| **touch**                 | 修改时间和新建文件  |
|                           |                     |

| chatter 【+- =】 | 文件隐藏属性                 |
| ---------------- | ---------------------------- |
| A                | 不修改atime                  |
| S                | 同步写入                     |
| a                | 只能增加数据                 |
| c                | 自动压缩 解压                |
| d                | 不会被dump 程序备份          |
| i                | 不能删除 修改建立链接        |
| s                | 直接从硬盘删除               |
| u                | 文件删除时数据内容存在磁盘中 |
| **lsattr**       | 查看隐藏属性                 |

+ **getcwd(char *buf, size_t size)**---获取当前路径函数

  头文件 <unistd.h>

  参数一 ： 存放当前工作的绝对路径

  参数二 ：存放路径数组的大小 （应保证足够大） 

  失败返回null 

+ **getopt(int argc, char *const argv[], const char *optstring);**-----用于判断传入参数的函数

  头文件<unistd.h>

  参数 一 二  接受命令行参数

  参数三 选项字符串

  extern char * optarg   用于保存选项参数 nl -b a  a就是选项参数 

  extern  int optind       记录下一个检索位置

  extern int opterr      将错误信息输出到stderr  为0 时表示不输出

  extern int optopt     不在选项字符串optstring中的选项

+ **chadir(const char *path)**   --- 改变当前路径

  头文件<unistd.h>

  失败返回-1

  成功返回0;

+ **struct dirent**    ---用于存储文件基本信息

  unsigned short d_reclen;   --- 文件名长

  unsigned char d_type;   --- 文件类型

  char  d_name[name_max + 1]  --- 文件名

+ **opendir() readdir()** --打开和读取目录

  opendir （） 用来打开参数name 指定的目录，并返回DIR*形态目录流.

  readdir ()  读取目录

+ **stat(const char *file_name, struct stat *buf)** ---获取文件状态函数

  把文件file_name 的状态 存储到buf结构体中

  头文件 <sys/stat.h>  <unistd.h>

  返回值 成功返回0  失败返回-1 

+ 命令与文件的查询

  + which   

    查找PATH路径下的所有可执行文件

  + whereis    查找特定文件

    | -b   | 查找二进制文件            |
    | ---- | ------------------------- |
    | -m   | 只查找manual路径下的 文件 |
    | -s   | 只查找source源文件        |
    | -u   | 其他文件                  |
    |      |                           |

  + locate 

     模糊定为查找  运用索引文件查找，

    | -i               | 忽略大小写         |
    | ---------------- | ------------------ |
    | -r               | 后面接正则表达式   |
    | 相关配置文件     | /etc/updatedb.conf |
    | 查找文件索引位置 | /ect/lib/mlocate   |

  + **find**

    高级查找功能

    | 与时间相关的       | -atime  -mtime -ctime                 |
    | ------------------ | ------------------------------------- |
    | -mtime n           | n天前的“一天之内“修改过的文件         |
    | -mtime  +n         | n天之前，不包含n， 修改过得文件       |
    | -mtime  -n         | n天之内，包含n，修改过得文件          |
    | -newer  file       | 比file 还要新的文件                   |
    | **与用户和组相关** | **find 【path】【option】【action】** |
    | -uid    n          | 用户UID、为n                          |
    | gid  n             | 群组GID为n                            |

    | -user name               | 用户名为name                          |
    | ------------------------ | ------------------------------------- |
    | -group name              | 群组名为name                          |
    | nouser                   | 文件所有者不存在                      |
    | nogroup                  | 文件所在组不存在                      |
    | **与文件权限及名称有关** | **find 【path】 【option】 【action】 |
    | -name filename           | 文件名filename                        |
    | -size 【+-】SIZE         | 查找比SIZE大或小的                    |
    | -type  TYPE fbcdlsp      | 查找其中文件类型                      |
    | -perm mode               | mode刚好等于的文件                    |
    | -perm  -mode             | 全部包含mode的文件                    |

    | -EXEC 的用法                       |                                                              |
    | ---------------------------------- | ------------------------------------------------------------ |
    | find   语句   -exec  ls -l {}  \； | find执行  语句后  通过 -exec把 结果放到{ }里面，执行到；结束 |

    

### #shell编程基础

case $i in 

​	1 )

; ;

esac 

数组 declare -a  num

或这  name【123】= value

name=（123,123）数组全部就两个值

${#num[@]}  求数组个数

￥{！num【@】}  找到数组下表

num+=（a b c） 数组追加

unset删除数组或元素

unset b   unset b【122】

$$ 当前进程pid

￥！ 上一个指令的 pid

￥{pa ：-我的人} 表达式为woef

￥{pa：=word} 为设施变量 未定义 返回值为 word 并赋值给变量

￥{pa：？word}  未定义就退出

￥{pa：+wod}如果已定义返回word

￥{！pre*} 前缀匹配  pre开头bianliang 

# #awk  eval   命令学习 

 