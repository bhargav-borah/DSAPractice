class Solution {
public:
    int getMax(vector<vector<int>>& mat, int col) {
        int numRows = mat.size();
        int row = -1;
        int maxi = INT_MIN;
        for (int i = 0; i < numRows; i++) {
            if (mat[i][col] > maxi) {
                maxi = mat[i][col];
                row = i;
            }
        }

        return row;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int numRows = mat.size();
        int numCols = mat[0].size();
        int low = 0, high = numCols - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = getMax(mat, mid);
            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < numCols ? mat[row][mid + 1] : -1;
            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            }
            else if (left > mat[row][mid]) {
                high = mid - 1;
            }
            else if (right > mat[row][mid]) {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};
// class Solution {
// public:
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
//         int numRows = mat.size();
//         int numCols = mat[0].size();
//         int maxi = INT_MIN;
//         vector<int> output;

//         for (int i = 0; i < numRows; i++) {
//             for (int j = 0; j < numCols; j++) {
//                 if (mat[i][j] > maxi) {
//                     maxi = mat[i][j];
//                     output = {i, j};
//                 }
//             }
//         }

//         return output;
//     }
// };
// class Solution {
// public:
//     bool isPeak(vector<vector<int>>& mat, int i, int j) {
//         int numRows = mat.size();
//         int numCols = mat[0].size();
//         bool val = true;
//         // (i+1, j)
//         // (i-1, j)
//         // (i, j+1)
//         // (i, j-1)
//         if (i + 1 == numRows) {
//             val = val && true;
//         }
//         else {
//             val = val && (mat[i][j] > mat[i + 1][j]);
//         }
//         if (!val) return false;

//         if (i - 1 == -1) {
//             val = val && true;
//         }
//         else {
//             val = val && (mat[i][j] > mat[i - 1][j]);
//         }
//         if (!val) return false;

//         if (j + 1 == numCols) {
//             val = val && true;
//         }
//         else {
//             val = val && (mat[i][j] > mat[i][j + 1]);
//         }
//         if (!val) return false;

//         if (j - 1 == -1) {
//             val = val && true;
//         }
//         else {
//             val = val && (mat[i][j] > mat[i][j - 1]);
//         }
//         if (!val) return false;

//         return val;
//     }
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
//         int numRows = mat.size();
//         int numCols = mat[0].size();

//         for (int i = 0; i < numRows; i++) {
//             for (int j = 0; j < numCols; j++) {
//                 if (isPeak(mat, i, j)) return {i, j};
//             }
//         }

//         return {-1, -1};
//     }
// };