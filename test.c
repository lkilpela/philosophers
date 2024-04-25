#include <stdio.h>
#include <unistd.h> 
#include <sys/time.h>

long long get_time(void)
{
	struct timeval	tv;

    gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000000 + tv.tv_usec / 1000);    
}

/*void	usleep(int time)
{
	int	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(50);	
}*/

int main() {
    int philosopher;

    printf("Current time: %lld\n", get_time());

    printf("Philosopher is going to sleep for 1 second...\n");
    usleep(1000); // Sleep for 1 second (1000 milliseconds)

    printf("Philosopher woke up.\n");
    printf("Current time: %lld\n", get_time());

    return 0;
}