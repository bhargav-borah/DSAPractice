class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a: asteroids) {
            while (!st.empty() && a < 0 && st.top() > 0) {
                int diff = a + st.top();
                if (diff < 0) {
                    st.pop();
                }
                else if (diff > 0) {
                    a = 0;
                }
                else if (diff == 0) {
                    a = 0;
                    st.pop();
                }
            }
            if (a != 0) {
                st.push(a);
            }
        }

        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};