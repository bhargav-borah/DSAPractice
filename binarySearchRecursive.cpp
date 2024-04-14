#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int target, int low, int high) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    
    if (nums[mid] == target) return mid;
    else if (nums[mid] > target) return binarySearch(nums, target, low, mid - 1);
    else return binarySearch(nums, target, mid + 1, high);
}

int main()
{
    vector<int> arr = {1, 3, 3, 5, 6, 11};
    int target;
    cin >> target;
    
    int res = binarySearch(arr, target, 0, arr.size() - 1);
    if (res != -1) {
        cout << target << " found at index " << res << "." << endl;
    }
    else {
        cout << target << " not found in array." << endl;
    }
    
    return 0;
}
