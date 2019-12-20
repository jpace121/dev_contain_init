#include <iostream>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    while(true)
    {
        int status;
        waitpid(-1, &status, WNOHANG);
    }
    
    return 0;
}
