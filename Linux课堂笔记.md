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
  + 非对称加密 --->rsa
  + 信息摘要

- **免密登录**

  + ssh -keygen    --->生成秘钥
  + ssh - copy -id  ~/.ssh/id_rsa.pub   --->把秘钥复制到 树莓派

- **编译文件  成一个可执行文件**

  + gcc tcp.c -o  check  --->把 tcp.c   编译成一个 可执行文件  check

- **github的免密链接 并 上传文件**

  + 先把主机公钥放到 github上面
  + github 建库 并执行远程连接
    + git remote add origin git@github.com:zhengyang0106/Euler.git
    + git add *  --->追踪要上传文件  * 代表全部文件
    + git commit -m "备注"--->设置备注信息
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

- **echo的用法**

  + echo $PATH  查看path下的信息  
  + 

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

  -------

  