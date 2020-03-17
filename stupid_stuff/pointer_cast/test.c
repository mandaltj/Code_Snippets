#include <iostream>

int main(){
    unsigned int * arr_int_0 = (unsigned int *)malloc(2*sizeof(unsigned int));
    arr_int_0[0] = 2;
    arr_int_0[1] = 7;
    std::cout<<arr_int_0[0]<<'\n';
    std::cout<<arr_int_0[1]<<'\n';

    //"arr_int_0" and "&arr_int_0[0]" print the same
    //arr_int_0 - This is a pointer; Printing this gives the address for the array
    //&arr_int_0[0] - This prints the address of the first element which is the same as above
    std::cout<<arr_int_0<<'\n';
    std::cout<<&arr_int_0[0]<<'\n';
    std::cout<<&arr_int_0[1]<<'\n';
    //Try see the prints!!

    char * arr_char_0 = (char *)arr_int_0;
    std::cout<<arr_char_0[0]<<'\n';
    std::cout<<arr_char_0[1]<<'\n';
    std::cout<<arr_char_0[2]<<'\n';
    std::cout<<arr_char_0[3]<<'\n';
    std::cout<<arr_char_0[4]<<'\n';
    std::cout<<arr_char_0[5]<<'\n';
    std::cout<<arr_char_0[6]<<'\n';
    std::cout<<arr_char_0[7]<<'\n';

    free(arr_int_0);
    return 0;
}
