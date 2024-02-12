#include <iostream>
using namespace std;

void insertion_sort(int[], int);
void print_array(int[], int);

int main() {
    int arr[] = {8, 2, 9, 5, 6, 7, 4, 3, 1};
    insertion_sort(arr, sizeof(arr) / sizeof(*arr));
    print_array(arr, sizeof(arr) / sizeof(*arr));

    return 0;
}

void insertion_sort(int arr[], int length) {
    for (int i = 1; i < length; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print_array(int arr[], int length) {
    cout << "Sorted array: ";
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
