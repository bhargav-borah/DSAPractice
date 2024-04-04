vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    res.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return res;
    }
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     set<vector<int>> st;

    //     for (int i = 0; i < n - 2; i++) {
    //         unordered_set<int> hashset;
    //         for (int j = i + 1; j < n; j++) {
    //             int third = -(nums[i] + nums[j]);
    //             if (hashset.find(third) != hashset.end()) {
    //                 vector<int> temp = {nums[i], nums[j], third};
    //                 sort(temp.begin(), temp.end());
    //                 st.insert(temp);
    //             }
    //             hashset.insert(nums[j]);
    //         }
    //     }

    //     vector<vector<int>> res(st.begin(), st.end());
        
    //     return res;
    // }
// vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>> st;
//         vector<vector<int>> res;

//         for (int i = 0; i < n - 2; i++) {
//             for (int j = i + 1; j < n - 1; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     if (nums[i] + nums[j] + nums[k] == 0) {
//                         vector<int> vec = {nums[i], nums[j], nums[k]};
//                         sort(vec.begin(), vec.end());
//                         st.insert(vec);
//                     } 
//                 }
//             }
//         }

//         for (auto it: st) {
//             res.push_back(it);
//         }

//         return res;
//     }