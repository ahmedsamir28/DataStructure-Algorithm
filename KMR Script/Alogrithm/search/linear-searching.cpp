#include <iostream>
using namespace std;

int linear_search(int[],int,int);

int main(){
    int arr[] = {8,2,9,5,6,7,4,3};
    cout << linear_search(arr , 6 ,sizeof(arr)/sizeof(*arr));
    return 0;
}

int linear_search(int arr[] , int n , int length){
    for (int i = 0; i < length; i++)
    {
        if (arr[i]==n) return i ;
    }
    return -1;
}