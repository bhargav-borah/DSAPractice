class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> mpp;
        stack<int> st;

        for (int i = 0; i < nums1.size(); i++) {
            mpp[nums1[i]] = i;
        }

        for (int i = 0; i < nums2.size(); i++) {
            if (!st.empty() && nums2[i] > st.top()) {
                while (!st.empty() && nums2[i] > st.top()) {
                    ans[mpp[st.top()]] = nums2[i];
                    st.pop(); 
                }
            }
            if (mpp.find(nums2[i]) != mpp.end()) st.push(nums2[i]);
        }

        return ans;
    }
};
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans(nums1.size(), -1);
//         unordered_map<int, int> mpp;

//         for (int i = 0; i < nums1.size(); i++) {
//             mpp[nums1[i]] = i;
//         }

//         for (int i = 0; i < nums2.size() - 1; i++) {
//             if (mpp.find(nums2[i]) != mpp.end()) {
//                 for (int j = i + 1; j < nums2.size(); j++) {
//                     if (nums2[j] > nums2[i]) 
//                     {
//                         ans[mpp[nums2[i]]] = nums2[j];
//                         break;
//                     }
//                 }
//             }
            
//         }

//         return ans;
//     }
// };