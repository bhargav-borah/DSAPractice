class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0, rightSum = 0;
        int left = k - 1, right = n - 1;

        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        
        int maxi = leftSum;

        while (left >= 0) {
            leftSum -= cardPoints[left--];
            rightSum += cardPoints[right--];
            maxi = max(maxi, leftSum + rightSum);
        }

        return maxi;
    }
};