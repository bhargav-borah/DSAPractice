int countSmallerThanEqualToMid(vector<int>& row, int mid) {
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = 1, high = 1e9;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 0; i < m; i++) {
            count += countSmallerThanEqualToMid(matrix[i], mid);
        }

        if (count <= (m * n) / 2) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}
// int median(vector<vector<int>> &matrix, int m, int n) {
//     vector<int> arr;

//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             arr.push_back(matrix[i][j]);
//         }
//     }

//     sort(arr.begin(), arr.end());

//     return arr[(m * n) / 2];
// }