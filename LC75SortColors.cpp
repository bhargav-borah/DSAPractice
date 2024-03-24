class Solution {
public:
void sortColors(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else if (nums[mid] == 2) {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
    // void sortColors(vector<int>& nums) {
    //     vector<int> counts(3);
    //     for (auto it: nums) {
    //         if (it == 0) counts[0]++;
    //         else if (it == 1) counts[1]++;
    //         else if (it == 2) counts[2]++;
    //     }

    //     int iter = 0;

    //     while (counts[0]--) {
    //         nums[iter++] = 0;
    //     }

    //     while (counts[1]--) {
    //         nums[iter++] = 1;
    //     }

    //     while (counts[2]--) {
    //         nums[iter++] = 2;
    //     }
    // }
};