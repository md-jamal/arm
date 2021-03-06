#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

#define SIZE 128


int main(void)
{
    int fdr = -1;
    int fdw = -1;
    int ret = 0;
    char buf[SIZE];

    struct pollfd fds[2];

    //以只读的方式打开管道1
    fdr = open("fifo1", O_RDONLY);
    if (fdr < 0)
    {
        perror("open"); 
        goto err0;
    }
    printf("open fifo1 for read succesfully...\n");

    //以只写的方式打开管道2
    fdw = open("fifo2", O_WRONLY);
    if (fdw < 0)
    {
        perror("open"); 
        goto err0;
    }
    printf("open fifo2 for write succesfully...\n");

    
    while(1)
    {
        fds[0].fd = STDIN_FILENO;   //文件描述符
        fds[0].events = POLLIN; //表示有数据可读

        fds[1].fd = fdr;   //文件描述符
        fds[1].events = POLLIN; //表示有数据可读


    
        ret = poll(fds, 2, 3000);
        //出错的情况
        if (-1 == ret)
        {
            perror("poll");  
            break;
        }
        else if (0 == ret)
        {
            printf("3 second time out....\n"); 
            continue;
        }
        else 
        {
            //管道有数据读
            if (fds[1].revents & POLLIN)  
            {
                memset(buf, 0, SIZE); 
                ret = read(fdr, buf, SIZE);
                if (ret <= 0)
                    continue;
                buf[ret] = '\0';
                printf("read from fifo:  %s\n", buf); 
            }

            //标准输入有数据读
            if (fds[0].revents & POLLIN)
            {
                memset(buf, 0, SIZE); 
                ret = read(STDIN_FILENO, buf, SIZE);
                if (ret <= 0)
                    continue;
                buf[ret - 1] = 0; 
                ret = write(fdw, buf, ret);
                if (ret <= 0)
                    perror("write");
            }
        
        }
    }

    close(fdr);
    close(fdw);

    return 0;
err0:
    return -1;
}



