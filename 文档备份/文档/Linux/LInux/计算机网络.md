连接树莓派pi2`ssh -p 6532 ChongH@zentao.haizeix.tech`

端口:0-65536

TCP协议

	三次握手(建立连接)
	
	四次挥手(释放连接)

## SOCKET编程

#### socket套接字

- Socket是应用层与TCP/IP协议族通信的中间软件抽象层
- 套接字描述符
  - 一个小整数描述符来标识一个套接字
- 通信过程
  - 服务器端先初始化Socket，然后与端口绑定(bind)，对端口进行监听(listen)，调用accept阻塞，等待客户端连接
  - 在这时如果有个客户端初始化一个Socket，然后连接服务器(connect)，如果连接成功，这时客户端与服务器端的连接就建立了
  - 客户端发送数据请求，服务器端接收请求并处理请求，然后把回应数据发送给客户端，客户端读取数据，最后关闭连接，一次交互结束

- 主机字节序与网络字节序
  - 在将一个地址绑定到socket的时候,先将主机字节序转化为网络字节序.

create

 建立新套接字,bind listen

父进程和子进程执行同一片代码块

	子进程pid=0

server:

	192.168.1.40
	
	端口:8731

- `perror(const char *)`
  - 先打印字符串,然后输出当前errno值所对应的错误提示信息

#### socket() 

- socket函数对应于普通文件的打开操作。普通文件的打开操作返回一个文件描述字，而socket()用于创建一个socket描述符，它唯一标识一个socket。这个socket描述字跟文件描述字一样，后续的操作都有用到它，把它作为参数，通过它来进行一些读写操作
- `int sockfd = socket(AF_INET, SOCK_STREAM, 0)`
- 当我们调用socket创建一个socket时，返回的socket描述字它存在于协议族空间中，但没有一个具体的地址。如果想要给它赋值一个地址，就必须调用bind()函数，否则就当调用connect()、listen()时系统会自动随机分配一个端口

```c
int socket(int domain, int type, int protool)
协议族domain: AF_INET...
socket类型type: SOCK_STREAM...
协议protocol
```

#### bind()

- 绑定IP地址及端口
- 客户端就不用指定，有系统自动分配一个端口号和自身的ip地址组合

```c
int bind(sockfd, const struct sockaddr *addr, socketlen_t addrlen)
sockfd是调用socket返回的描述符
addr是指向数据结构sockaddr的指针,保存你的地址(即端口和IP地址)信息
addrlen设置为sizeof(struct sock)
```

- 相关结构体

```c
struct sockaddr_in{
    sa_family_t sin_family;
    in_port_t sin_port;
    struct in_addr sin_addr;
}
struct in_addr{
   uint32_t s_addr;
}
```

#### 网络字节序与主机字节序

```c
htons()将端口号由主机字节序转换为网络字节序的整数值
	myaddr.sin_port = htons(8731)
ntohl()相反
inet_addr()将一个IP字符串转换为一个网络字节序的整数值
	sockaddr_in.sin_addr.s_addr = inet_addr("192.168.1.2")
inet_ntoa()将一个sin_addr结构体输出成字符串
inet_aton(server_addr_string, &myaddr.sin_addr)
// 尝试转换由strptr所指的字符串,并通过addrptr存放二进制结果
int inet_pton(int family, const char *strptr, void *addrptr)

// 进行相反转换,从数值格式转换到表达格式
const char *inet_ntop(int family, const void *addrptr, char *strptr, size_t len)

```

#### listen()

- 如果作为一个服务器，在调用socket()、bind()之后就会调用listen()来监听这个socket，如果客户端这时调用connect()发出连接请求，服务器端就会接收到这个请求

```c
int listen(int sockfd, int backlog);
backlog可以取20,即排队列中的数目
```

- connect()建立连接

```c
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
connect函数的第一个参数即为客户端的socket描述字，第二参数为服务器的socket地址，第三个参数为socket地址的长度。客户端通过调用connect函数来建立与TCP服务器的连接
```

#### accept()

- 接收连接,**产生新socket**

```c
int accpet(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
//返回连接connect_fd
当有连线进来时,accept()会返回一个新的socket处理代码,往后的数据传送与读取都是经由新的socket处理
addr是一个结果参数，它用来接受一个返回值，这返回值指定客户端的地址，当然这个地址是通过某个地址结构来描述的，用户应该知道这一个什么样的地址结构。如果对客户的地址不感兴趣，那么可以把这个值设置为NULL
addrlen它也是结果的参数，用来接受上述addr的结构的大小的，它指明addr结构所占有的字节个数。同样的，它也可以被设置为NULL
```

#### close()

- 关闭连接

`int close(int fd)`

- close一个TCP socket的缺省行为时把该socket标记为以关闭，然后立即返回到调用进程。该描述字不能再由调用进程使用，也就是说不能再作为read或write的第一个参数

#### 网络IO操作

- send 将数据发送到缓冲区
  - 返回值为发送了多少
  - 注意第三个参数不要用sizeof,**要用strlen**,即有多少发多少.

- recv 从缓冲区中接受数据
  - 返回值为-1,0,>0,为0时代表对方关闭连接,>0时为收到了多少字节

- recvmsg/sendmsg

fork()产生一个子进程(分身)

父进程有的子进程都有

当pid=0时说明为子进程



#### 客户端向服务端发送文件(内容)

- 服务端获取客户端IP

```c
ac_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &addr_len)
printf("%s", inet_ntoa(client_addr.sin_addr))
```

- fflush(stdout)清空输出缓冲区,并把缓冲区内容输出

- fread(array, size_t size, size_t count, fp)
  - 第二个参数为每次读取的元素大小
  - 第三个参数为做多读取到的元素个数
  - array为读入的数组,fp为要读的文件

**在数组结尾加个\0才能正常显示**

????返回值不是读取元素的个数,若读到,则为1,为何?

bzero(buffer, sizeof(buffer)) 清零



