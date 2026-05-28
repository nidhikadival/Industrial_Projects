#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

//  ./cdx       DirectoryPath     
//   argv[0]    argv[1]     
//  argc = 2

/*
    1. Accept new diredtory path
    2. Call chdir with that path
    3. Call getcwd to check the changed path
*/

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("ERROR : Insufficient Arguments\n");
        printf("Use as : ./cdx    DirectoryPath\n");
        return -1;
    }

    
    if(chdir(argv[1]) == -1)
    {
        printf("ERROR : Unable to change current working directory\n");
        return -1;
    }

    char Buffer[256] = {'\0'};

    getcwd(Buffer,sizeof(Buffer)-1);
    
    printf("Current directory changed to : %s\n",Buffer);
    
    return 0;
}