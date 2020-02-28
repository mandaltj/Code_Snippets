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
    std::cout<<"myarr Size: "<<sizeof(myarr)<<'\n';
    std::cout<<"myarr[] Size: "<<sizeof(myarr[0])<<'\n';
    std::cout<<"myarr[][] Size: "<<sizeof(myarr[0][0])<<'\n';
    std::cout<<"myarr[][][] Size: "<<sizeof(myarr[0][0][0])<<'\n';

    int ***test_arr = (int ***)malloc(x_dim*sizeof(int**));
    for(int i=0; i<x_dim; i++){
        test_arr[i] = (int **)malloc(y_dim*sizeof(int *));
        for(int j=0; j<y_dim; j++){
            // std::cout<<"Here!!\n";
            test_arr[i][j] = (int *)malloc(z_dim*sizeof(int));
        }
    }
    std::cout<<"test_arr Size: "<<sizeof(test_arr)<<'\n';
    std::cout<<"test_arr[] Size: "<<sizeof(test_arr[0])<<'\n';
    std::cout<<"test_arr[][] Size: "<<sizeof(test_arr[0][0])<<'\n';
    std::cout<<"test_arr[][][] Size: "<<sizeof(test_arr[0][0][0])<<'\n';
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

    test_arr[0][0][0] = 1;

    //We can't simply use delete[] myarr to delete this 3D array.
    for(int i=0; i<x_dim; i++){
        for(int j=0; j<y_dim; j++){
            // std::cout<<"Here!!\n";
            delete [] myarr[i][j];
        }
        delete [] myarr[i];
    }
    delete [] myarr;

    for(int i=0; i<x_dim; i++){
        for(int j=0; j<y_dim; j++){
            // std::cout<<"Here!!\n";
            delete [] test_arr[i][j];
        }
        delete [] test_arr[i];
    }
    delete [] test_arr;


    std::cout<<"Double** size:"<<sizeof(double **)<<'\n';
    std::cout<<"Int** size:"<<sizeof(int **)<<'\n';
    std::cout<<"Double* size:"<<sizeof(double *)<<'\n';
    std::cout<<"Int* size:"<<sizeof(int *)<<'\n';
    std::cout<<"Double size:"<<sizeof(double)<<'\n';
    std::cout<<"Int size:"<<sizeof(int)<<'\n';

    int * arr_1 = (int *)malloc(4*sizeof(int));
    arr_1[0] = 1;
    arr_1[1] = 2;
    arr_1[2] = 3;
    arr_1[3] = 4;
    arr_1[4] = 5;
    std::cout<<"arr_1 size:"<<sizeof(arr_1)<<'\n';
    std::cout<<arr_1[0]<<'\n';
    std::cout<<arr_1[1]<<'\n';
    std::cout<<arr_1[2]<<'\n';
    std::cout<<arr_1[3]<<'\n';
    std::cout<<arr_1[4]<<'\n';

    return 0;
}
