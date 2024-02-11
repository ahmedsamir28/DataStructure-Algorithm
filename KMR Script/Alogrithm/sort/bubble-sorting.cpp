#include <iostream>
using namespace std;

void bubble_sort(int[], int);
void print_array(int[], int);

int main() {
    int arr[] = {8, 2, 9, 5, 6, 7, 4, 3, 1};
    bubble_sort(arr, sizeof(arr) / sizeof(*arr));
    print_array(arr, sizeof(arr) / sizeof(*arr));

    return 0;
}

void bubble_sort(int arr[], int length) {
    bool isSwapped;
    for (int i = 0; i < length - 1; ++i) {
        isSwapped = false;
        for (int j = 0; j < length - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = true;
            }
        }
        // If no two elements were swapped in the inner loop, then the array is already sorted
        if (!isSwapped) {
            break;
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
