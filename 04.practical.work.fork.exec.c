#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int val=fork();
    if (val==0)
    {
        char *A[] = {"ps","-ef",NULL};
        execvp("ps",A);
    }
    else
    {
        wait(NULL);
        val=fork();
        if (val==0)
        {
            char *A[] = {"free","-h",NULL};
            execvp("free",A);
        }
        else
        {
            wait(NULL);
        }
    }
    return 0;
}



