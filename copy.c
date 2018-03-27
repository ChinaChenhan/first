#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define IFERR(x,y)   if(x==-1)\
    {\
        perror(#y);\
        return -1;\
    }
int main(void)
{
    int fd=open("abc.txt",O_CREAT|O_RDWR,0666);
    IFERR(fd,open);
    int fd2=open("123.txt",O_RDONLY);
    IFERR(fd2,open);
    char buffer[1024]={0};
    read(fd2,buffer,sizeof(buffer));
    write(fd,buffer,strlen(buffer));
    close(fd);
    close(fd2);
}