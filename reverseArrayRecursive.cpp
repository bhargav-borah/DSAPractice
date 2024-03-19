#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseArray(int arr[], int start, int end) {
    if (start ==  end) return;
    
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    
    reverseArray(arr, start + 1, end - 1);
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, size);
    
    reverseArray(arr, 0, size - 1);
    
    cout << "Reversed array: ";
    printArray(arr, size);
    
    return 0;
}