class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) majorityElement = nums[i];
            
            if (nums[i] == majorityElement) count++;
            else count--;
        }

        return majorityElement;
    }

    // int majorityElement(vector<int>& nums) {
    //     map<int, int> mpp;
    //     for (auto it: nums) {
    //         if (mpp.find(it) == mpp.end()) mpp[it] = 1;
    //         else mpp[it]++;

    //         if (mpp[it] > nums.size() / 2) return it;
    //     }

    //     return -1;
    // }
};