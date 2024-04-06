#include<bits/stdc++.h>

int getLongestZeroSumSubarrayLength(vector<int>& arr) {
	int n = arr.size();
	unordered_map<int, int> mpp;
	int sum = 0;
	int maxLen = 0;
	
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum == 0) {
			maxLen = i + 1;
		}
        else {
			if (mpp.find(sum) != mpp.end()) {
				maxLen = max(maxLen, i - mpp[sum]);
            } 
			else {
                mpp[sum] = i;
            }
        }
	}

	return maxLen;
}
// int getLongestZeroSumSubarrayLength(vector<int> &arr){
// 	int n = arr.size();
// 	int maxLen = 0;

// 	for (int i = 0; i < n; i++) {
// 		int sum = 0;
// 		for (int j = i; j < n; j++) {
// 			sum += arr[j];
// 			if (sum == 0) maxLen = max(maxLen, j - i + 1);
// 		}
// 	}

// 	return maxLen;
// }