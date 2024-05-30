#include <bits/stdc++.h>
using namespace std;

void nearestSmallerInteger(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> input = {4, 5, 2, 10, 8};
    nearestSmallerInteger(input);
    

    return 0;
}
