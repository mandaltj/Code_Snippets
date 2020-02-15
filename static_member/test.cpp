#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include "test.h"

std::vector<check> core_check;

std::string filename = "input.txt";
std::ifstream infile(filename);
if(!infile) {
	infile.close();
	throw std::runtime_error("Could not load file: " + filename);
}

std::string str_line;
while (std::getline(infile, str_line)) {
	std::istringstream is( str_line );

}
infile.close();


https://stackoverflow.com/a/22114337/4422502
int main()
{



    std::vector<int> v( ( std::istream_iterator<int>( is ) ), std::istream_iterator<int>() );

    for ( int x : v) std::cout << x << ' ';
    std::cout << std::endl;

    return 0;
}
