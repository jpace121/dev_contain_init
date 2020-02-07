// Copyright 2019-2020 James Pace
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include <iostream>
#include <sys/wait.h>
#include <csignal>
#include <unistd.h>

void sigchild_handler(int signal)
{
    int status;
    waitpid(-1, &status, WNOHANG);
}

int main(int argc, char *argv[])
{
    if(not (getpid() == 1))
    {
        std::cerr << "dev_contain_init must be ran as pid 1. Exiting." << std::endl;
        std::exit(-1);
    }
    std::signal(SIGCHLD, sigchild_handler);

    std::cout << "dev_contain_init running." << std::endl;
    while(true)
    {
        pause();
    }
    return 0;
}
