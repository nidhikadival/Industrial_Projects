#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

//  ./touchx    FileName.txt     
//   argv[0]    argv[1]     
//  argc = 2

/*
    1. Accept the file name from command line 
    2. Check whether file is existing
    3. If it exists : return
    4. If not existing : Create the file
*/

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("ERROR : Insufficient Arguments\n");
        printf("Use as : ./touchx    FileName\n");
        return -1;
    }

    if(access(argv[1],F_OK) == 0)  // already exists
    {
        return 0;
    }
    else
    {
        creat(argv[1],0777);
    }

    return 0;
}