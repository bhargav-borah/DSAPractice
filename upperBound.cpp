int upperBound(vector<int> &arr, int x, int n){
	int res = n;

	int low = 0;
	int high = n - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] > x) {
			res = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}	
	// int res = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
	return res;
}