#include <fstream>
#include <iostream>
#include "test.h"
#include "test.cpp"
#include <unistd.h>

std::string get_current_dir(){
    char buff[FILENAME_MAX];
    getcwd(buff, FILENAME_MAX);
    std::string current_working_dir(buff);
    return current_working_dir;
}

int main(){
    Core::print_apu_policy();

    //On running this program we will observe that the static member
    //"APU_policy" of Class "Core" will be initialized only once
    //irrespective  of the number of objects of Class "Core"

    std::cout<<"Current Directory: "<<get_current_dir()<<'\n';

    Core A(0, 10, 1);
    Core B(1, 5, 1);
    Core C(2, 13, 1);
    Core D(3, 20, 0);
    Core E(4, 19, 0);

    std::cout<<A.test()<<'\n';
    std::cout<<B.test()<<'\n';
    std::cout<<C.test()<<'\n';
    std::cout<<D.test()<<'\n';
    std::cout<<E.test()<<'\n';

    return 0;
}
