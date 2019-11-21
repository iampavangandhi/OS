#include <stdio.h>

int main()
{
    
    
			printf("\nAmount of Memory Configured in System\n");
			system("awk 'NR==4(printf $0)' /proc/meminfo");
			printf("\nMemory Currently in System\n");
			system("awk 'NR==5(printf $0)' /proc/meminfo");
	
}
