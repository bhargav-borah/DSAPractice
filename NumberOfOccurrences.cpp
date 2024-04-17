# include <bits/stdc++.h>
using namespace std;

int getLowerBound(vector<int>& arr, int target) {
	int n = arr.size();
	int low = 0, high = n - 1;
	int res = n;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] >= target) {
			res = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return res;
}

int getUpperBound(vector<int>& arr, int target) {
	int n = arr.size();
	int low = 0, high = n - 1;
	int res = n;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] > target) {
			res = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return res;
}

int count(vector<int>& arr, int n, int x) {
	if (n == 0) return 0;

	int starting = getLowerBound(arr, x);
	if (starting == n || arr[starting] != x) return 0;

	int ending = getUpperBound(arr, x) - 1;

	return ending - starting + 1;
}

// # include <bits/stdc++.h>
// using namespace std;

// int count(vector<int>& arr, int n, int x) {
// 	if (n == 0) return 0;

// 	int starting = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
// 	if (arr[starting] != x || starting == n) return 0;

// 	int ending = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;

// 	return ending - starting + 1;
// }