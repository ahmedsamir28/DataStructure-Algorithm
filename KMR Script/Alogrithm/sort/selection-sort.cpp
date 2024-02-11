#include <iostream>
using namespace std;

void selection_sort(int[], int);
void print_array(int[], int);

int main() {
    int arr[] = {8, 2, 9, 5, 6, 7, 4, 3, 1};
    selection_sort(arr, sizeof(arr) / sizeof(*arr));
    print_array(arr, sizeof(arr) / sizeof(*arr));

    return 0;
}

void selection_sort(int arr[], int length) {
    for (int i = 0; i < length - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < length; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void print_array(int arr[], int length) {
    cout << "Sorted array: ";
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
