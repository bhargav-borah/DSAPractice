int lowerBound(vector<int> arr, int n, int x) {
	int low = 0;
	int high = n - 1;

	int res = n;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] >= x) {
			res = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
		
	}
	// int res = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	return res;
}
