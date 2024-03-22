// Time complexity: O(n), Space complexity: O(1)
vector<int> rotateArray(vector<int>arr, int k) {
    int n = arr.size();

    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());

    return arr;
}

// Time complexity: O(n), Space complexity: O(n)
// vector<int> rotateArray(vector<int>arr, int k) {
//     int n = arr.size();
//     vector<int> a(n);
    
//     for (int i = 0; i < n; i++) {
//         a[(i - k + n) % n] = arr[i];
//     }

//     return a;
// }


