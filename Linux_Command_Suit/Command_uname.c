#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/utsname.h>

//  ./unamex         
//   argv[0]    
//  argc = 1

/*
    1. Call the system call uname
    2. Print the information from utsname structure
*/

int main(int argc, char * argv[])
{
    struct utsname obj;
    int iRet = 0;

    iRet = uname(&obj);

    if(iRet == -1)
    {
        printf("ERROR : Unable to fetch system information\n");
        return -1;
    }

    printf("Operating System name : %s\n",obj.sysname);
    printf("Node name : %s \n",obj.nodename);
    printf("Operating System Version : %s \n",obj.release);

    return 0;
}