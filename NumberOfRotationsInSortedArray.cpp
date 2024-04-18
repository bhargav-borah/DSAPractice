#include <bits/stdc++.h>

int findKRotation(vector<int> &arr){
    // We just need to find the index of the minimum element
    // That would be the number of the times the sorted array has been rotated
    int low = 0, high = arr.size() - 1;
    int minIdx = -1;
    int mini = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[mid]) { // left half of search space is sorted
            if (arr[low] < mini) {
                mini = arr[low];
                minIdx = low;
            }
            low = mid + 1;
        }
        else {                              // right half of search space is sorted
            if (arr[mid] < mini) {
                mini = arr[mid];
                minIdx = mid;
            }
            high = mid - 1;
        }
    }

    return minIdx;
}