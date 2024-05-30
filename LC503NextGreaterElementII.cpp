class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = 0; i < 2 * n; i++) {
            while (!st.empty() && nums[i % n] > nums[st.top()]) {
                res[st.top()] = nums[i % n];
                st.pop();
            }
            if (i < n) st.push(i);
        }

        return res;
    }
};
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> res(n, -1);

//         for (int i = 0; i < n; i++) {
//             for (int j = 1; j < n; j++) {
//                 if (nums[(i + j) % n] > nums[i]) {
//                     res[i] = nums[(i + j) % n];
//                     break;
//                 }
//             }
//         }
        
//         return res;
//     }
// };