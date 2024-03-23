class Solution {
public:
    int getMax(int num1, int num2) {
        if (num1 >= num2) return num1;
        return num2;
    }
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;

        for (auto it: nums) {
            if (it == 1) {
                count++;
            }
            else if (it == 0 && count != 0) {
                maxi = getMax(maxi, count);
                count = 0;
            }
        }

        if (count != 0) maxi = getMax(maxi, count);

        return maxi;
    }
};