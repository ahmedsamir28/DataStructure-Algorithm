#include <iostream>
using namespace std;

int binary_search(int[],int,int);

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    cout << binary_search(arr , 7,sizeof(arr)/sizeof(*arr));
    return 0;
}

int binary_search(int arr[] , int n , int length){
    int start = 0;
    int end = length-1;
    int middle; 

    while (end >= start)
    {
        middle = start + (end-start) / 2;
        if (arr[middle] == n) return middle;
        else if(arr[middle] > n) end = middle - 1;
        else start = middle + 1;
    }
    return -1;
}