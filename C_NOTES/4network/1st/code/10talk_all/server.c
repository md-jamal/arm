#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <unistd.h>


#define PORT 10086
#define SIZE 128

#define my_gets(buf, size) do{          \
    fgets(buf, SIZE, stdin);            \
    if (buf[strlen(buf) - 1] == '\n')   \
    buf[strlen(buf) - 1] = '\0';    \
    else                                \
    while('\n' != getchar())        \
    ;                           \
}while(0)

/*
 *
 *服务端:
 *    a. 创建一个套字
 *    b. 初始化结构体
 *    c. 绑定
 *    d. 监听 设置监听队列的大小
 *    e. 接受客户端的连接
 *    f. 读写操作
 *
 */

int main(void)
{

    int sockfd = 0;
    int newfd = 0;
    int ret = -1;
    int i = 0;
    char buf[SIZE];
    int a[10] = {0};
    struct sockaddr_in sockaddr;
    struct sockaddr_in fromaddr;
    socklen_t len = sizeof(fromaddr);

    int fd_max;
    fd_set readfds;
    struct timeval tmo;

    //a. 创建套接字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd)
    {
        perror("socket"); 
        goto err0;
    }
    //b. 初始化结构体
    memset(&sockaddr, 0, sizeof(sockaddr));
    sockaddr.sin_family = AF_INET; //ipv4
    sockaddr.sin_port = htons(PORT);
    sockaddr.sin_addr.s_addr = inet_addr("2.2.2.88");


    //绑定
    ret = bind(sockfd, (void*)&sockaddr, sizeof(sockaddr));
    if (-1 == ret)
    {
        perror("bind"); 
        goto err1;
    }

    //监听
    ret = listen(sockfd, 10);
    if (-1 == ret)
    {
        perror("listen"); 
        goto err1;
    }

    printf("server is waiting the client incomming....\n");


    fd_max = sockfd > STDIN_FILENO ? sockfd + 1 : STDIN_FILENO + 1;

    //读写操作
    while(1)
    {
        fd_max = sockfd;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        for (i = 0; i < 10; i++)
        {
            if (0 != a[i])
            {
                FD_SET(a[i], &readfds); 
                fd_max = fd_max > a[i] ? fd_max : a[i];
            }
        }

        FD_SET(STDIN_FILENO, &readfds);

        tmo.tv_sec = 3;
        tmo.tv_usec = 0;

        ret = select(fd_max + 1, &readfds, NULL, NULL, &tmo);
        if (ret < 0)
        {
            perror("select"); 
            goto err0;
        }
        else if (0 == ret)
        {
            printf("timeout 3s\n"); 
        }
        else
        {
            //表示有客户链接
            if (FD_ISSET(sockfd, &readfds))
            {
                //阻塞 接受客户端连接
                newfd = accept(sockfd, (void*)&fromaddr, &len);
                if (-1 == newfd)
                {
                    perror("accept"); 
                    goto err1;
                }
                //客户端的信息
                printf("from client  ip: %s port: %d\n", inet_ntoa(fromaddr.sin_addr), ntohs(fromaddr.sin_port));
                //在缓冲区中找一个位置存放套接字
                for (i = 0; i < 10; i++)
                {
                    if (0 == a[i]) 
                    {
                        a[i] = newfd;
                        break;
                    }
                }

                if (10 == i)
                {
                    printf("QQ群满员 加入失败...\n"); 
                    close(newfd);
                }
            }

            for (i = 0; i < 10; i++)
            {
                //读数据
                if (FD_ISSET(a[i], &readfds))  
                {
                    ret = read(a[i], buf, SIZE); 
                    buf[ret] = 0;
                    if (ret <= 0)
                    {
                        a[i] = 0;
                        continue;
                    }
                    printf("from client:  %s\n", buf);
                    //子进程做事
                    if (fork() == 0)
                    {
                        for (i = 0; i < 10; i++) 
                        {
                            if (0 != a[i])
                            {
                               ret = write(a[i], buf, strlen(buf)); 
                               if (ret < 0)
                                    a[i] = 0;
                            }
                        }
                        exit(0);
                    }
                }
            }

        }
    }

    close(sockfd);
    return 0;
err1:
    close(sockfd);
err0:
    return -1;
}
