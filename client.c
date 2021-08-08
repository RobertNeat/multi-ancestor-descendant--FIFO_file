#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
    char tekst[30]="";
    int fd;
    
    while(1){
        fd=open("/tmp/myfifo",O_RDONLY);
        read(fd,tekst,30);
        if(strlen(tekst)!=0){
        printf("Server sent: %s\n",tekst);
        }
        close(fd);
    }
}