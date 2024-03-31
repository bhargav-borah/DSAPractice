vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
    
        int up = 0;
        int down = matrix.size() - 1;
        
        int left = 0;
        int right = matrix[0].size() - 1;
        
        while (true) {
            for (int i = left; i <= right; i++) output.push_back(matrix[up][i]);
            up++;
            if (left > right || up > down) break;

            for (int i = up; i <= down; i++) output.push_back(matrix[i][right]);
            right--;
            if (left > right || up > down) break;

            for (int i = right; i >= left; i--) output.push_back(matrix[down][i]);
            down--;
            if (left > right || up > down) break;
            
            for (int i = down; i >= up; i--) output.push_back(matrix[i][left]);
            left++;
            if (left > right || up > down) break;
        }
        
        return output;
    }