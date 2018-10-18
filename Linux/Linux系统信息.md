## 系统信息

- uptime

  -s 开机时间

  -p 美观显示

- w 获得当前登录用户和正在执行的进程

  -h 不打印头信息

  w -h | awk \'{print $2}\'

  w -h user 只看某个用户的

- wall 广播

- who 显示当前登录系统的用户信息

- whoami 打印当前有效的用户名称

  who am i 显示实际登录的用户

- id 输出用户名, 所在组名,

- last 显示用户最近登录信息

  -f  "file" 

  数据文件一般放在/var(系统动态信息)

- uname 打印当前系统信息

  查看内核版本等

- date 显示或设置系统时间与日期

  +日期格式

  -s "string" 设置时间(不建议, 建议用NTP)

  -d "string" 显示字符串所指日期

- cal 显示日历

#### BIOS用来硬件检测,引导系统由Boot loader做