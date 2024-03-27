void getNextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        for (int i = n - 1; i > idx && idx != -1; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        reverse(nums.begin() + idx + 1, nums.end());
    }
    void nextPermutation(vector<int>& nums) {
        getNextPermutation(nums);
    }
    // Using STL
    // void nextPermutation(vector<int>& nums) {
    //     next_permutation(nums.begin(), nums.end());
    // }