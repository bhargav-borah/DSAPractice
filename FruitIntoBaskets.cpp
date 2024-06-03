class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int left = 0, right = 0;
        int maxi = 0;
        unordered_map<int, int> mpp;
        
        while (right < fruits.size()) {
            mpp[fruits[right]]++;
            
            while (mpp.size() > 2) {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0) mpp.erase(fruits[left]);
                left++;
            }
            
            if (mpp.size() <= 2) {
                maxi = max(maxi, right - left + 1);
            }
            
            right++;
        }
        
        return maxi;
    }
};
// class Solution {
//   public:
//     int totalFruits(int N, vector<int> &fruits) {
//         int n = fruits.size();
//         int maxi = 0;
        
//         for (int i = 0; i < n; i++) {
//             set<int> st;
//             for (int j = i; j < n; j++) {
//                 st.insert(fruits[j]);
//                 if (st.size() <= 2) {
//                     maxi = max(maxi, j - i + 1);
//                 }
//             }
//         }
        
//         return maxi;
//     }
// };