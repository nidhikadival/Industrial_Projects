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
    if(access(argv[1],F_OK) != 0)       // File does not exist
    {
        printf("mv: rename %s to %s: No such file or directory\n",argv[1],argv[2]);
        return -1;
    }
    else
    {
        if(rename(argv[1], argv[2]) == -1)
        {
            printf("ERROR : Unable to move\n");
            return -1;
        }
    }

    return 0;
}