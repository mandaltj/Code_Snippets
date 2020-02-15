#include <fstream>    //Required for ifstream and ofstream
#include <iostream>
#include <vector>
#include <sstream>
//Code to read from a file and store all the words seprated by space into a vector string
int main(){
    std::string filename = "README.md";
    std::ifstream infile(filename);
    if(!infile) {
        infile.close();
        throw std::runtime_error("Could not load file: " + filename);
    }

    //Storing the strings in a Vector of strings
    std::vector<std::string> file_string_list;
    std::string str_line;
    std::string x;
    //Getline gets a line from the file input and stores it as string in str_line
    while (std::getline(infile, str_line)){
        //str_line is converted to "is" which is a sort of iterator
        std::istringstream is(str_line);
        while(is >> x){
            file_string_list.push_back(x);
        }
    }

    std::cout<<"Printing out the strings: \n";
    for(auto get_str: file_string_list){
        std::cout<<get_str<<'\n';
    }

    return 0;
}
