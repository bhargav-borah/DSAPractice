#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    int maxi = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxi) maxi = arr[i];
    }

    return maxi;
}
