#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

//  ./catx    FileName.txt     
//   argv[0]    argv[1]     
//  argc = 2

/*
    1. Accept the file name from command line 
    2. Check whether file is existing
    3. If it exists then print on console
    4. If not existing : Display No such file or directory as a error
*/

#define MAX_BUFFER_SIZE 1024

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("ERROR : Insufficient Arguments\n");
        printf("Use as : ./catx    FileName\n");
        return -1;
    }

    if(access(argv[1],F_OK) != 0)   // does not exist
    {
        printf("cat: %s: No such file or directory\n",argv[1]);
        return -1;
    }
    else
    {
        int fd = 0;
        int iRet = 0;
        char Buffer[MAX_BUFFER_SIZE] = {'\0'};
        memset(Buffer,'\0',sizeof(Buffer));

        if(fd<0)
        {
            printf("ERROR : Unable to open the file\n");
        }

        fd = open(argv[1],O_RDONLY);

        while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0 )
        {
            write(1,Buffer,iRet);
            memset(Buffer,'\0',sizeof(Buffer));    
        }
        printf("\n");

        close(fd);
    }

    return 0;
}