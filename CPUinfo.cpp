#include <stdio.h>

int main()
{
    int ch;
    printf("Enter your Choice(1= CPU Type/2= CPU Time):");
    scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nCPU type and Model is:\n");
			system("awk 'NR==5(printf $5)' /proc/cpuinfo");
			printf("\nKernel Version is:\n");
			system("cat /proc/sys/kernel/osrelease");
			printf("\nAmount of time the System was last Booted\n");
			system("awk 'NR==1(printf $1)' /proc/uptime\n");break;

		case 2:
			printf("\nTime CPU spent in user mode, in system mode & when idle\n");
			system("awk 'NR==1(printf $2 " " $4 " " $5)' /proc/stat");
			printf("\nNumber of Accesses made to disk on the System\n");
			system("awk 'NR==7(printf $2)' /proc/stat");
			printf("\nTime at which the System was last Booted\n");
			system("awk 'NR==9(printf $2)' /proc/stat");
			printf("\nNumber of Context Switch Kernel has Performed\n");
			system("awk 'NR==8(printf $2)' /proc/stat");
			printf("\nNumber of Processes Created Since the System was last Booted\n");
			system("awk 'NR==10(printf $2)' /proc/stat");break;

		
	}
    return 0;
}
