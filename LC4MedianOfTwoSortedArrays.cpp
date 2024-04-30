class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int totalSize = nums1.size() + nums2.size();
    if (totalSize % 2 == 1) {
        return findKth(nums1, nums2, totalSize / 2 + 1);
    } else {
        return (findKth(nums1, nums2, totalSize / 2) + findKth(nums1, nums2, totalSize / 2 + 1)) / 2.0;
    }
}

    int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;

        while (true) {
            if (i == m) return nums2[j + k - 1];
            if (j == n) return nums1[i + k - 1];

            if (k == 1) return min(nums1[i], nums2[j]);

            int midA = min(i + k / 2, m);
            int midB = min(j + k / 2, n);

            if (nums1[midA - 1] < nums2[midB - 1]) {
                k -= midA - i;
                i = midA;
            } else {
                k -= midB - j;
                j = midB;
            }
        }
    }

}
// double median(vector<int>& a, vector<int>& b) {
// 	int n1 = a.size(), n2 = b.size();
// 	int n = n1 + n2;

// 	int idx1 = n / 2;
// 	int idx2 = (n / 2) - 1;

// 	int i = 0, j = 0;
// 	int count = 0;
// 	int ele1 = -1, ele2 = -1;

// 	while (i < n1 && j < n2) {
// 		if (a[i] <= b[j]) {
// 			if (count == idx1) ele1 = a[i];
// 			if (count == idx2) ele2 = a[i];
// 			count++;
// 			i++;
// 		}
// 		else {
// 			if (count == idx1) ele1 = b[j];
// 			if (count == idx2) ele2 = b[j];
// 			count++;
// 			j++;
// 		}
// 	}

// 	while (i < n1) {
// 		if (count == idx1) ele1 = a[i];
// 		if (count == idx2) ele2 = a[j];
// 		count++;
// 		i++;
// 	}

// 	while (j < n2) {
// 		if (count == idx1) ele1 = b[j];
// 		if (count == idx2) ele2 = b[j];
// 		count++;
// 		j++;
// 	}

// 	if (n % 2 == 0) return (double)(ele1 + ele2) / 2.0;
// 	else return (double)ele1;
// }

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