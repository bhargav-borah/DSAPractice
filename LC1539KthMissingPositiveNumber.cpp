class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missingNums = arr[mid] - (mid + 1);
            if (missingNums < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // int more = k - (arr[high] - (high + 1));
        // return arr[high] + more; // arr[high] + k - arr[high] + high + 1 = k + high + 1;
        if (high < 0) return k;
        return k + high + 1;
    }
};

// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int n = arr.size();
//         for (int i = 0; i < n; i++) {
//             if (arr[i] <= k) k++;
//             else break;
//         }

//         return k;
//     }
// };

// class Solution {
// public:
//     bool isPresent(vector<int>& arr, int target) {
//         int n = arr.size();
//         for (int i = 0; i < n; i++) {
//             if (arr[i] == target) return true;
//         }

//         return false;
//     }

//     int findKthPositive(vector<int>& arr, int k) {
//         int n = arr.size();
//         int target = 1;

//         while (k != 0) {
//             if (!isPresent(arr, target)) {
//                 k--;
//             };
//             if (k == 0) return target;
//             target++;
//         }

//         return target;
//     }
// };