class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n, 0), maxRight(n, 0);

        int maxi = height[0];
        maxLeft[0] = 0;
        for (int i = 1; i < n; i++) {
            maxLeft[i] = maxi;
            maxi = max(maxi, height[i]);
        }

        maxi = height[n - 1];
        maxRight[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = maxi;
            maxi = max(maxi, height[i]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int val = min(maxLeft[i], maxRight[i]) - height[i];
            if (val > 0) res += val;
        }

        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int maxLeft = height[left], maxRight = height[right];
        int res = 0;

        while (left < right) {
            if (maxLeft < maxRight) {
                left++;
                maxLeft = max(maxLeft, height[left]);
                res += maxLeft - height[left];
            }
            else {
                right--;
                maxRight = max(maxRight, height[right]);
                res += maxRight - height[right];
            }
        }

        return res;
    }
};