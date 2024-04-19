int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] > nums[mid - 1]) { // index mid is on increasing slope -> peak lies to the right of mid
                low = mid + 1;
            }
            else {  // index mid is on decreasing slope -> peak lies to the left of mid
                high = mid - 1;
            }
        }

        return 0;
    }
// int findPeakElement(vector<int> &arr) {
//     int n = arr.size();
//     if (arr[0] > arr[1]) return 0;
//     if (arr[n - 1] > arr[n - 2]) return n - 1;

//     for (int i = 1; i <= n - 2; i++) {
//         if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
//             return i;
//         }
//     }
// }