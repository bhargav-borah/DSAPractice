// Time complexity: O(n), Space complexity: O(1)
void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.begin() + (n - k));
        reverse(nums.begin() + (n - k), nums.end());
        reverse(nums.begin(), nums.end());
        }

// Time complexity: O(n), Space complexity: O(n)
// void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> a(n);
//         for (int i = 0; i < n; i++) {
//             a[(i + k) % n] = nums[i];
//         }

//         for (int i = 0; i < n; i++) nums[i] = a[i];
//     }        