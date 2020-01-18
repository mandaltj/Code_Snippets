#include <iostream>

int main(){
	int x_dim = 4;
	int y_dim = 4;
	int z_dim = 3;

	int ***myarr = new int**[x_dim];
	for(int i=0; i<x_dim; i++){
		myarr[i] = new int*[y_dim];
		for(int j=0; j<y_dim; j++){
			// std::cout<<"Here!!\n";
			myarr[i][j] = new int[z_dim];
		}
	}

	//myarr is a pointer to an array of pointer to pointer of length x_dim
	//myarr[i] is a pointer to an array of pointer of length y_dim
	//myarr[i][j] is a pointer to an array of integers of length z_dim

	std::cout<<"Display 3D Array: \n";
	for(int i=0; i<x_dim; i++){
		std::cout<<"[";
		for(int j=0; j<y_dim; j++){
			std::cout<<"[";
			for(int k=0; k<z_dim; k++){
				std::cout<<myarr[i][j][k]<<",";
			}
			std::cout<<"], ";
		}
		std::cout<<"]\n";
	}

	//We can't simply use delete[] myarr to delete this 3D array.
	for(int i=0; i<x_dim; i++){
		for(int j=0; j<y_dim; j++){
			// std::cout<<"Here!!\n";
			delete [] myarr[i][j];
		}
		delete [] myarr[i];
	}
	delete [] myarr;

	return 0;
}
