#include <bits/stdc++.h>

int getNumberOfGasStations(vector<int>& arr, double distance) {
	int n = arr.size();
	int count = 0;

	for (int i = 0; i < n - 1; i++) {
		int numberInBetween = (arr[i + 1] - arr[i]) / distance;
		if (numberInBetween * distance == arr[i + 1] - arr[i]) numberInBetween--;
		count += numberInBetween;
	}

	return count;
}

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	double low = 0;
	double high = -1;

	for (int i = 0; i < n - 1; i++) {
		high = max(high, (double)(arr[i + 1] - arr[i]));
	}

	while (high - low > 1e-6) {
		double mid = (low + high) / 2.0;
		int numberOfGasStations = getNumberOfGasStations(arr, mid);
		if (numberOfGasStations > k) {
			low = mid;
		}
		else {
			high = mid;
		}
	}

	return high;
}

// double minimiseMaxDistance(vector<int> &arr, int k){
// 	int n = arr.size();
// 	vector<int> howMany(n - 1, 0);
// 	priority_queue<pair<double, int>> pq;

// 	for (int i = 0; i < n - 1; i++) {
// 		pq.push({arr[i + 1] - arr[i], i});
// 	} 

// 	for (int gasStations = 1; gasStations <= k; gasStations++) {
// 		auto topEle = pq.top();
// 		int idx = topEle.second;
// 		pq.pop();

// 		howMany[idx]++;

// 		double diff = arr[idx + 1] - arr[idx];
// 		double newSectionLength = diff / (howMany[idx] + 1);
// 		pq.push({newSectionLength, idx});
// 	}

// 	return pq.top().first;
// }

// double minimiseMaxDistance(vector<int> &arr, int k){
// 	int n = arr.size();
// 	vector<int> howMany(n - 1, 0);

// 	for (int gasStations = 1; gasStations <= k; gasStations++) {
// 		long double maxSectionLength = -1;
// 		int maxIdx = -1;

// 		for (int i = 0; i < n - 1; i++) {
// 			long double diff = arr[i + 1] - arr[i];
// 			long double sectionLength = diff / (howMany[i] + 1);
// 			if (sectionLength > maxSectionLength) {
// 				maxSectionLength = sectionLength;
// 				maxIdx = i;
// 			}

// 		}
// 		howMany[maxIdx]++;
// 	}	

// 	long double maxDist = -1;
// 	for (int i = 0; i < n - 1; i++) {
// 		long double diff = arr[i + 1] - arr[i];
// 		long double sectionLength = diff / (howMany[i] + 1);
// 		maxDist = max(maxDist, sectionLength);
// 	}

// 	return maxDist;
// }
