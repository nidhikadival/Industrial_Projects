#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

//  ./mvx       SourcePath     DestPath
//   argv[0]    argv[1]     argv[2]
//  argc = 3

/*
    1. Accept the file name from command line 
    2. Check whether file is existing
    3. if does not exists : print error No such file or directory
    4. if exists : rename
*/

int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        printf("ERROR : Insufficient Arguments\n");
        printf("Use as : ./mvx    SourceFilename     DestinationFilename\n");
        return -1;
    }

    if(rename(argv[1], argv[2]) == -1)
    {
        printf("ERROR : Unable to move\n");
        return -1;
    }

    return 0;
}