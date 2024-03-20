#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int hash[100] = {0};
    
    int arr[5] = {1, 2, 1, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < size; i++) {
        hash[arr[i]]++;
    }
    
    cout << hash[5] << endl;

    return 0;
}