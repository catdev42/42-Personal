#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    
    char* fileName = "sample.txt";

    int fd = open(fileName, O_RDWR);
    
    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }
    else{
        printf("\nFile %s opened sucessfully!\n", fileName);
    }

    char buffer[2];

    int bytesRead = read(fd, buffer, 2);



    printf("%d bytes read!\n", bytesRead);
    printf("File Contents: %s\n", buffer);

    return 0;
}