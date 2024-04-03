class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int threshold = n / 3;

        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;

        for (int num: nums) {
            if (candidate1 == num) count1++;
            else if (candidate2 == num) count2++;
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0, count2 = 0;
        for (int num: nums) {
            if (num == candidate1) count1++;
            if (num == candidate2) count2++;
        }

        if (count1 > threshold) res.push_back(candidate1);
        if (count2 > threshold && candidate1 != candidate2) res.push_back(candidate2);

        return res;
    }
};

ector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 3;
        vector<int> res;

        unordered_map<int, int> mpp;
        for (auto it: nums) mpp[it]++;
        for (auto it: mpp) {
            if (it.second > threshold) res.push_back(it.first);
        }

        return res;
    }
    
// vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> res;

//         for (int i = 0; i < n; i++) {
//             if (res.size() == 0 || res[0] != nums[i]) {
//                 int count = 0;
//                 for (int j = 0; j < n; j++) {
//                     if (nums[i] == nums[j]) count++;  
//                     if (count > (n / 3)) {
//                         res.push_back(nums[i]);
//                         break;
//                     }
//                 }
//             }   
//         }

//         return res;
//     }