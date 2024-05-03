class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();

        int low = 0, high = numRows * numCols - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / numCols;
            int col = mid % numCols;
            if (target == matrix[row][col]) return true;
            else if (target > matrix[row][col]) low = mid + 1;
            else if (target < matrix[row][col]) high = mid - 1;
        }

        return false;
    }
};
// class Solution {
// public:
//     bool binarySearch(vector<int>& arr, int target) {
//         int low = 0, high = arr.size() - 1;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (target == arr[mid]) return true;
//             else if (target > arr[mid]) low = mid + 1;
//             else if (target < arr[mid]) high = mid - 1;
//         }

//         return false;
//     }

//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int numRows = matrix.size();
//         int numCols = matrix[0].size();

//         for (int i = 0; i < numRows; i++) {
//             if ((matrix[i][0] <= target) && (target <= matrix[i][numCols - 1])) {
//                 return binarySearch(matrix[i], target);
//             }
//         }

//         return false;
//     }
// };
// class Solution {
// public:
//     bool binarySearch(vector<int>& arr, int target) {
//         int low = 0, high = arr.size() - 1;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (target == arr[mid]) return true;
//             else if (target > arr[mid]) low = mid + 1;
//             else if (target < arr[mid]) high = mid - 1;
//         }

//         return false;
//     }

//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int rows = matrix.size();
//         int cols = matrix[0].size();

//         int rowLow = 0, rowHigh = rows - 1;
//         while (rowLow <= rowHigh) {
//             int rowMid = rowLow + (rowHigh - rowLow) / 2;
//             if (matrix[rowMid][0] <= target && target <= matrix[rowMid][cols - 1]) {
//                 return binarySearch(matrix[rowMid], target);
//             }
//             else if (target > matrix[rowMid][cols - 1]) {
//                 rowLow = rowMid + 1;
//             }
//             else if (target < matrix[rowMid][0]) {
//                 rowHigh = rowMid - 1;
//             }
//         }

//         return false;
//     }
// };