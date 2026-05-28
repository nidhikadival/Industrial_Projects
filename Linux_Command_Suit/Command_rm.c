#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

//  ./rmx    FileName.txt     
//   argv[0]    argv[1]     
//  argc = 2

/*
    1. Accept the file name from command line 
    2. Check whether file is existing
    3. If it exists : delete the file
    4. If not existing : print error No such file or directory
*/

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("ERROR : Insufficient Arguments\n");
        printf("Use as : ./rmx    FileName\n");
        return -1;
    }

    if(access(argv[1],F_OK) == 0)  // already exists
    {
        if( unlink(argv[1]) == -1)
        {
            printf("ERROR : Unable to delete\n");
            return -1;
        }
        else
        {
            printf("%s file deleted successfully\n",argv[1]);
        }
    }
    else
    {
        printf("rm: %s: No such file or directory\n",argv[1]);
        return -1;
    }

    return 0;
}