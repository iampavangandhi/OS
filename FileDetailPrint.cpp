#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc,char *argv[])
{
    struct stat buf;
    if(argc < 2)
	    printf("Error:Insufficient parameters:");

	stat(argv[1],&buf);
    printf("File name is %s\n",argv[1]);
    printf("User id:%d\n",buf.st_uid);

	if(S_ISREG(buf.st_mode))
	{
        printf("%s is a regular file\n",argv[1]);
    }

	if(buf.st_mode & 0400)
	{
        printf("User has read permission\n");
    }

	if(buf.st_mode & 0200)
	{
        printf("User has write permission\n");
    }

	if(buf.st_mode & 0100)
	{
        printf("User has execute permission\n");
    }

	if(buf.st_mode & 0040)
	{
        printf("Group has read permission\n");
    }

	if(buf.st_mode & 0020)
	{
        printf("Group has write permission\n");
    }

	if(buf.st_mode & 0010)
	{
        printf("Group has execute permission\n");
    }

	if(buf.st_mode & 0004)
	{
        printf("Others have read permission\n");
    }

	if(buf.st_mode & 0002)
	{
        printf("Others have write permission\n");
    }

	if(buf.st_mode & 0001)
	{
        printf("Others have execute permission\n");
    }
    return 0;
}
