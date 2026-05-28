#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

//  ./statx     Filename         
//   argv[0]    argv[1]
//  argc = 2

/*
    1. Accept file name from command line
    2. Call access to check if file exists
    3. Call stat system call to get file metadata
    4. Display the metadata
*/

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("ERROR : Insufficient Arguments\n");
        printf("Use as : ./statx    FileName\n");
        return -1;
    }

    if(access(argv[1],F_OK) == 0)  // already exists
    {
        struct stat sobj;
        int iRet = 0;

        iRet = stat(argv[1],&sobj);

        if(iRet == -1)
        {
            printf("ERROR : Unable to fetch statistical information\n");
            return -1;
        }

        printf("File name : %s\n",argv[1]);
        printf("File size : %ld\n",(long) sobj.st_size);
        printf("Inode number : %ld\n",(long) sobj.st_ino);
    }
    else
    {
        printf("ERROR : File not found\n");
        return -1;
    }

    return 0;
}