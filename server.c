#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
    mkfifo("/tmp/myfifo",0777);
    char text[30];
    int fd;

    for(int a=0;a<10;a++){
        fd=open("/tmp/myfifo",O_WRONLY);
        sprintf(text,"Server: sending line nr %d",a);
        printf("%s\n",text);        
        write(fd,text,30);
        close(fd);
        sleep(1);
    }
    return 0;
}
