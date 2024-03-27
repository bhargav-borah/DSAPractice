vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int posIdx = 0, negIdx = 1;
        for (auto it: nums) {
            if (it > 0) {
                res[posIdx] = it;
                posIdx += 2;
            }
            else {
                res[negIdx] = it;
                negIdx += 2;
            }
        }

        return res;
    }

// Brute force solution
// vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> posNums, negNums, res(nums.size());
//         for (auto it: nums) {
//             if (it > 0) posNums.push_back(it);
//             else negNums.push_back(it);
//         }

//         int iter = 0;
//         for (auto it: posNums) {
//             res[iter] = it;
//             iter += 2;
//         }

//         iter = 1;
//         for (auto it: negNums) {
//             res[iter] = it;
//             iter += 2;
//         }

//         return res;
//     }