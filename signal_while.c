#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h> 
#include <unistd.h>

int exit_s=5;
void handle_sigint(int sig) 
{ 
    exit_s--;
    printf("almost already, click more %d\n", exit_s);
    if (exit_s==0)
    {
        printf("close program (-.-)\n");
        exit(0);
    }
    
} 
int main ()
{
    int i=0;
     signal(SIGINT, handle_sigint);
    while (i<100)
    {
        i++;
        sleep(1);
        printf("\tmassage №%d\n",i);
    
    }
    return 0;
}
