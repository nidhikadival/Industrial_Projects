#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

//  ./lsx       -i
//   argv[0]    argv[1]   
//  argc = 2

/*
    1. Open the current directory (".")
    2. Read all entries from that directory
    3. Print the name of files
    4. Close the directory
*/

int main(int argc, char * argv[])
{

    int option = 0;
    // 1 : ls -a
    // 2 : ls -i

    if(argc == 1)       // normal ls
    {
        option = 1;
    }
    else if(strcmp(argv[1],"-a") == 0)      // ls -a
    {
        option = 1;
    }
    else if(strcmp(argv[1],"-i") == 0)      // ls -i
    {
        option = 2;
    }
    else
    {
        printf("ERROR : There is no such option\n");
    }

    char * path = ".";

    DIR *dp = NULL;

    dp = opendir(path);
    if(dp == NULL)
    {
        printf("ERROR : Unable to open directory\n");
        return -1;
    }

    struct dirent *dobj;

    while((dobj = readdir(dp)) != NULL)
    {
        if(option == 1)
        {
            printf("%s\n",dobj->d_name);
        }
        else if(option == 2)
        {
            printf("%llu\t%s\n",dobj->d_ino,dobj->d_name);
        }
    }

    closedir(dp);

    return 0;
}