int upperBound(vector<int>& matrix, int target) {
    int n = matrix.size();
    int result = n;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (matrix[mid] > target) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1; 
        }
    }

    return result;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int maxi = INT_MIN;
    int rowIdx = -1;

    for (int i = 0; i < n; i++) {
        int count = m - upperBound(matrix[i], 0);
        if (count > maxi) {
            maxi = count;
            rowIdx = i;
        }
    }

    return rowIdx;
}
// int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
// {
//     int maxi = INT_MIN;
//     int rowIdx = -1;

//     for (int i = 0; i < n; i++) {
//         int count = m - (upper_bound(matrix[i].begin(), matrix[i].end(), 0) - matrix[i].begin());
//         if (count > maxi) {
//             maxi = count;
//             rowIdx = i;
//         }
//     }

//     return rowIdx;
// }
// int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
// {
//     int maxi = INT_MIN;
//     int rowIdx = -1;

//     for (int i = 0; i < n; i++) {
//         int count = 0;
//         for (int j = 0; j < m; j++) {
//             count += matrix[i][j];
//         }
//         if (count != 0) {
//             if (count > maxi) {
//                 maxi = count;
//                 rowIdx = i;
//             }
//         }
//     }

//     return rowIdx;
// }