#include <boost/process.hpp>
#include <iostream>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    auto result = boost::process::system("echo 'Hi'");

    while(true)
    {
        int status;
        waitpid(-1, &status, WNOHANG);
    }
    
    return 0;
}
