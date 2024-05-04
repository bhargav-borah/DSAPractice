class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        int row = 0, col = numCols - 1;
        while (row < numRows && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (target < matrix[row][col]) col--;
            else if (target > matrix[row][col]) row++;
        }

        return false;
    }
};

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int numRows = matrix.size();
//         int numCols = matrix[0].size();
//         int row = 0, col = numCols - 1;
//         while (row < numRows && col >= 0) {
//             if (matrix[row][col] == target) return true;
//             else if (target < matrix[row][col]) col--;
//             else if (target > matrix[row][col]) row++;
//         }

//         return false;
//     }
// };