#include <fstream>
#include <iostream>
#include "test.h"
#include "test.cpp"

int main(){
    Core::print_apu_policy();

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
