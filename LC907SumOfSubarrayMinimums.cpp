class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> ple(n, -1); // previous less element
        vector<int> nle(n, n);  // next less element

        stack<int> st;
        // Calculate PLE (Previous Less Element)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) ple[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        // Calculate NLE (Next Less Element)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) nle[i] = st.top();
            st.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            int leftCount = i - ple[i];
            int rightCount = nle[i] - i;
            res = (res + static_cast<long long>(arr[i]) * leftCount * rightCount) % MOD;
        }

        return static_cast<int>(res);
    }
};