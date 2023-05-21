# Memoryallocationmanagement
内存管理。在系统启动时开辟一定量的内存池，存储形式为多链表，每条链表上的内存大小一致，内存大小以及数量可通过宏配置。当需要动态申请内存的时候可从提前开辟好的内存池中获取，不再需要调用malloc和free，作用为减少程序运行时动态申请内存的系统调用时间。

使用
git clone [https://github.com/liaoyanbang/MessageManageControl.git](https://github.com/liaoyanbang/MessageManageControl.git)
./build.sh
printf result:

```c
get memory 0x55efbd5f42e0
The addr is in memory 0
find the addr and set null
get memory 0x55efbd5f84c0
```

内存池配置参数
/src/memory.h
![image.png](https://cdn.nlark.com/yuque/0/2023/png/25784032/1684655638671-b886c57b-8928-4dbd-940b-313ba2228b34.png#averageHue=%2321201f&clientId=u25bbb7ab-94ca-4&from=paste&height=308&id=ub547460e&originHeight=385&originWidth=335&originalType=binary&ratio=1.25&rotation=0&showTitle=false&size=22115&status=done&style=none&taskId=u9b333feb-6f08-43fd-b556-4d7d966b65a&title=&width=268)

usage

```c
  Memory_Allocal_Manage_Init();
  signal(SIGINT,INT_handler);

  int* addr = (int*)Memory_Allocal_Get(TYPE_SMALL);
  Memory_Allocal_Release(&addr);
  Memory_Allocal_Get(TYPE_HUGE);
```