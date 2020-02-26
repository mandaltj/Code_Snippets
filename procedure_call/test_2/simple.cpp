#include <iostream>

/*
int main(){
	int x = 100;
	int y = 200;
	int arr[1] = {1};
	printf("%d\n", arr[0]);
	printf("%d\n", arr[1]);
	printf("%d\n", arr[2]);
	return 0;
}
*/

int main(){
	int *arr = (int *)(1000);
    arr[0] = 1;
    arr[1] = 2;
    //int arr[1] = {1};
    std::cout<<arr<<'\n';
	return 0;
}
