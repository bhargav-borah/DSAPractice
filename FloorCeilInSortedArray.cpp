int getFloor(vector<int>& a, int x) {
	int n = a.size();
	int low = 0, high = n - 1;
	int res = -1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (a[mid] <= x) {
			res = a[mid];
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return res;
}

int getCeil(vector<int>& a, int x) {
	int n = a.size();
	int low = 0, high = n - 1;
	int res = -1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (a[mid] >= x) {
			res = a[mid];
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return res;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int floorVal = getFloor(a, x);
	int ceilVal = getCeil(a, x);

	return make_pair(floorVal, ceilVal);
}