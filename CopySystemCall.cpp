#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buff[50];
    int n;
    int fd1=open("source.txt",O_RDONLY);
    int fd2=open("target.txt",O_WRONLY||O_CREAT);
    if(fd1 < 0)
	    printf("\nSource File not Opened Successfully.\n");
	
	if(fd2 < 0)
	    printf("\nTarget File not Opened Successfully.\n");
	
	while((n=read(fd1,buff,50))>0)
	{
        write(fd2,buff,n);
    }

	write(fd2,"\0",1);

	if(n < 0)
	    printf("\nFile could not read the content.\n");

	close(fd1);
    close(fd2);
    fd2=open("target.txt",O_RDONLY);
    printf("\nFile 1 has been Copied to File 2 and its Contents are\n");

	while((n=read(fd2,buff,49))>0)
	{
        buff[49]='\0';
        printf(buff);
    }
    return 0;
}
