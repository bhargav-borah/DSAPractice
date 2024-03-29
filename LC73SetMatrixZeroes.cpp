void setZeroes(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        bool zeroRowFlag = false, zeroColFlag = false;

        for (int i = 0; i < cols; i++) {
            if (mat[0][i] == 0) {
                zeroRowFlag = true;
                break;
            }
        }

        for (int i = 0; i < rows; i++) {
            if (mat[i][0] == 0) {
                zeroColFlag = true;
                break;
            }
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (mat[i][j] == 0) {
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (mat[i][0] == 0 || mat[0][j] == 0) mat[i][j] = 0;
            }
        }

        if (zeroRowFlag) {
            for (int i = 0; i < cols; i++) mat[0][i] = 0;
        }

        if (zeroColFlag) {
            for (int i = 0; i < rows; i++) mat[i][0] = 0;
        }
    }

// void setZeroes(vector<vector<int>>& mat) {
//         int rows = mat.size();
//         int cols = mat[0].size();

//         unordered_set<int> rowZeroes, colZeroes;
        
//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 if (mat[i][j] == 0) {
//                     rowZeroes.insert(i);
//                     colZeroes.insert(j);
//                 }
//             }
//         }

//         for (auto row: rowZeroes) {
//             for (int i = 0; i < cols; i++) mat[row][i] = 0;
//         }

//         for (auto col: colZeroes) {
//             for (int i = 0; i < rows; i++) mat[i][col] = 0;
//         }
//     }