class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector<int> res(queries);
        for (int i = 0; i < indices.size(); i++) {
            int idx = indices[i];
            int count = 0;
            for (int i = idx + 1; i < arr.size(); i++) {
                if (arr[i] > arr[idx]) count++;
            }
            res[i] = count;
        }
        
        return res;
    }

};