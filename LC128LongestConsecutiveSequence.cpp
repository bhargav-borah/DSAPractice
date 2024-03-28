// Optimal Solution
int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int maxi = 1;
         
        unordered_set<int> st;
        for (auto it: nums) st.insert(it);

        for (auto it: st) {
            if (st.find(it - 1) == st.end()) {
                int count = 1;
                int ele = it;
                while (st.find(ele + 1) != st.end()) {
                    ele++;
                    count++;
                }
                maxi = max(maxi, count);
            }
        }

        return maxi;
    }

// Brute force solution
// bool isFound(vector<int>& a, int ele) {
//     for (auto it: a) if (it == ele) return true;
//     return false;
// }

// int longestSuccessiveElements(vector<int>&a) {
//     int maxi = 0;

//     for (int i = 0; i < a.size(); i++) {
//         int ele = a[i];
//         int count = 1;

//         while(isFound(a, ele + 1)) {
//             count++;
//             ele++;
//         }

//         maxi = max(maxi, count);
//     }

//     return maxi;
// }