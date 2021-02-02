#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>
#include "ae.h"
static aeEventLoop *g_el;
static int event_size = 10;
static int ipfd_count = 2;
static void beforeSleep()
{
    printf("before sleep\n");
}
static void afterSleep()
{
    printf("after sleep\n");
}
static int serverCron(struct aeEventLoop *eventLoop, long long id, void *clientData)
{
    printf("1 sec timer event\n");
    return 0;
}
static void acceptTcpHandler(aeEventLoop *el, int fd, void *privdata, int mask)
{
    int cport, cfd, max = 2;
    struct sockaddr_in raddr;
    socklen_t raddr_len;
    raddr_len = sizeof(raddr_len);
    char clie_IP[BUFSIZ];
    //最多创建1000个连接
    printf("acceptTcpHandler.\n");
    while (max--)
    {
        cfd = accept(fd,(struct sockaddr*)&raddr,&raddr_len);//在accept这里阻塞
        if (cfd < 0)
        {
            perror("accept");
            break;
        }
        printf("cfd:%d\n",cfd);

        printf("Client: %s  port:%d\n",
        inet_ntop(AF_INET, &raddr.sin_addr.s_addr, clie_IP, sizeof(clie_IP)), ntohs(raddr.sin_port));
        printf("%d conn left\n",max);
        // assert(0);
    }
}

static void acceptTcpHandler1(aeEventLoop *el, int fd, void *privdata, int mask)
{
    int cport, cfd, max = 2;
    struct sockaddr_in raddr;
    socklen_t raddr_len;
    raddr_len = sizeof(raddr_len);
    char clie_IP[BUFSIZ];
    //最多创建1000个连接
    printf("acceptTcpHandler1.\n");
    while (max--)
    {
        cfd = accept(fd,(struct sockaddr*)&raddr,&raddr_len);//在accept这里阻塞
        if (cfd < 0)
        {
            perror("accept");
            break;
        }
        printf("cfd:%d\n",cfd);

        printf("Client: %s  port:%d\n",
        inet_ntop(AF_INET, &raddr.sin_addr.s_addr, clie_IP, sizeof(clie_IP)), ntohs(raddr.sin_port));
        printf("%d conn left\n",max);
        // assert(0);
    }
}
int main(int argc, char const *argv[])
{
    g_el = aeCreateEventLoop(event_size);
    if (g_el == NULL) {
        perror("Failed creating the event loop. Error message:\n");
        exit(1);
    }

    // if (aeCreateTimeEvent(g_el, 3, serverCron, NULL, NULL) == AE_ERR)//创建一个周期性事件
    // {
    //     printf("Can't create event loop timers.\n");
    //     exit(1);
    // }
    int ipfd[ipfd_count];
    for (int i = 0; i < ipfd_count; i++)
    {
        ipfd[i] = socket(AF_INET, SOCK_STREAM,0);
        if (ipfd[i] < 0)
        {
            printf("Can't create socket.\n");
            exit(1);
        }
        printf("fd:%d\n",ipfd[i]);
        struct sockaddr_in laddr;
        laddr.sin_family = AF_INET;
        laddr.sin_port = htons(9999+i);
        inet_pton(AF_INET,"0.0.0.0",&laddr.sin_addr);
        if(bind(ipfd[i],(struct sockaddr *)&laddr,sizeof(laddr))<0)
        {
            perror("bind");
            exit(1);
        }
        if(listen(ipfd[i],5) < 0)
        {
            perror("listen");
            exit(1);	
        }
    }
    
    // for (int j = 0; j < ipfd_count; j++) 
    // {
    printf("socket :%d\n",ipfd[0]);
    if (aeCreateFileEvent(g_el,ipfd[0], AE_READABLE,acceptTcpHandler,NULL) == AE_ERR)
    {
        printf("Unrecoverable error creating server.ipfd file event.\n");
        exit(1);
    }
    // }   

    printf("socket :%d\n",ipfd[1]);
    if (aeCreateFileEvent(g_el,ipfd[1], AE_READABLE,acceptTcpHandler1,NULL) == AE_ERR)
    {
        printf("Unrecoverable error creating server.ipfd file event.\n");
        exit(1);
    }

    aeSetBeforeSleepProc(g_el,beforeSleep);
    aeSetAfterSleepProc(g_el,afterSleep);

    aeMain(g_el);//启动
    aeDeleteEventLoop(g_el);
    return 0;
}
