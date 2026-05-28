#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

//  ./cpx    Source.txt     Dest.txt
//   argv[0]    argv[1]     argv[2]
//  argc = 3

/*
    1. Open Source file for reading
    2. Create Destination file
    3. Read the data from source
    4. Write it into Destination
    5. Close both files
*/

#define MAX_BUFFER_SIZE 1024

int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        printf("ERROR : Insufficient Arguments\n");
        printf("Use as : ./cpx    SourceFilename     DestinationFilename\n");
        return -1;
    }

    int fdSrc = 0, fdDest = 0, iRet = 0;
    char Buffer[MAX_BUFFER_SIZE] = {'\0'};

    memset(Buffer,'\0',sizeof(Buffer));

    fdSrc = open(argv[1],O_RDONLY);
    if(fdSrc < -1)
    {
        printf("ERROR : Unable to open source file %s\n",argv[1]);
        return -1;
    }

    fdDest = creat(argv[2],0777);
    if(fdDest < -1)
    {
        printf("ERROR : Unable to create destination file %s\n",argv[2]);
        close(fdSrc);
        return -1;
    }

    while((iRet = read(fdSrc,Buffer,sizeof(Buffer))) != 0 )
    {
        write(fdDest,Buffer,iRet);
        memset(Buffer,'\0',sizeof(Buffer));     // Ensures that there is no garbage value in between the copy
    }

    printf("SUCCESS : copy activity done\n");

    close(fdSrc);
    close(fdDest);

    return 0;
}