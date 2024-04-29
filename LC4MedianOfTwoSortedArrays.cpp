double median(vector<int>& a, vector<int>& b) {
	int n1 = a.size(), n2 = b.size();
	int n = n1 + n2;

	int idx1 = n / 2;
	int idx2 = (n / 2) - 1;

	int i = 0, j = 0;
	int count = 0;
	int ele1 = -1, ele2 = -1;

	while (i < n1 && j < n2) {
		if (a[i] <= b[j]) {
			if (count == idx1) ele1 = a[i];
			if (count == idx2) ele2 = a[i];
			count++;
			i++;
		}
		else {
			if (count == idx1) ele1 = b[j];
			if (count == idx2) ele2 = b[j];
			count++;
			j++;
		}
	}

	while (i < n1) {
		if (count == idx1) ele1 = a[i];
		if (count == idx2) ele2 = a[j];
		count++;
		i++;
	}

	while (j < n2) {
		if (count == idx1) ele1 = b[j];
		if (count == idx2) ele2 = b[j];
		count++;
		j++;
	}

	if (n % 2 == 0) return (double)(ele1 + ele2) / 2.0;
	else return (double)ele1;
}

// double median(vector<int>& a, vector<int>& b) {
// 	int n1 = a.size(), n2 = b.size();
// 	vector<int> arr;

// 	int i = 0, j = 0;
// 	while (i < n1 && j < n2) {
// 		if (a[i] <= b[j]) arr.push_back(a[i++]);
// 		else arr.push_back(b[j++]);
// 	}

// 	while (i < n1) arr.push_back(a[i++]);
// 	while (j < n2) arr.push_back(b[j++]);

// 	int n = n1 + n2;
// 	if (n % 2 == 0) return (arr[(n / 2) - 1] + arr[(n / 2)]) / (double)2;
// 	else return (double)arr[n / 2];
// }