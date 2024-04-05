vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    
                    if (sum > target) {
                        l--;
                    }
                    else if (sum < target) {
                        k++;
                    }
                    else {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        st.insert(temp);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                }
            }
        }

        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }

// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         set<vector<int>> st;

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 set<int> hashset;
//                 for (int k = j + 1; k < n; k++) {
//                     int fourth = target - (nums[i] + nums[j] + nums[k]);
//                     if (hashset.find(fourth) != hashset.end()) {
//                         vector<int> temp = {nums[i], nums[j], nums[k], fourth};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                     hashset.insert(nums[k]);
//                 }
//             }
//         }

//         vector<vector<int>> res(st.begin(), st.end());
//         return res;
//     }

// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         set<vector<int>> st;

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     for (int l = k + 1; l < n; l++) {
//                         int sum = nums[i] + nums[j] + nums[k] + nums[l];
//                         if (sum == target) {
//                             vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
//                             sort(temp.begin(), temp.end());
//                             st.insert(temp);
//                         }
//                     }
//                 }
//             }
//         }

//         vector<vector<int>> res(st.begin(), st.end());
//         return res;
//     }