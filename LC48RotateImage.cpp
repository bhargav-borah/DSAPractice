void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > j) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }
    }

    void reverseRows(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = n - 1;

            while (start < end) {
                int temp = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = temp;

                start++;
                end--;
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverseRows(matrix);
    }