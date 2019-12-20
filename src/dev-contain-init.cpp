#include <iostream>
#include <csignal>

#include <sys/wait.h>
#include <signal.h>

static std::sig_atomic_t m_wait = 0;

//SIGCHILD 17
void wait_child(int signal)
{
    m_wait++;
}

int main(int argc, char *argv[])
{
    std::signal(SIGCHLD, wait_child);

    while(true)
    {
        if(m_wait > 0)
        {
            std::cout << "Reaping a process." << std::endl;
            
            int status;
            waitpid(-1, &status, WNOHANG);
            
            m_wait--;
        }
    }
    
    return 0;
}
