vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        res.push_back({1});
        if (numRows == 1) return res;

        res.push_back({1, 1});
        if (numRows == 2) return res;

        for (int i = 3; i <= numRows; i++) {
            vector<int> row(i);
            row[0] = row[row.size() - 1] = 1;
            vector<int> prevRow = res[res.size() - 1];
            for (int j = 1; j <= row.size() - 2; j++) {
                row[j] = prevRow[j - 1] + prevRow[j];
            }
            res.push_back(row);
        }

        return res;
    }