int kthElement(vector<int> &nums1, vector<int> &nums2, int m, int n, int k) {
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
      }
      else {
          k -= midB - j;
          j = midB;
      }
  }
}
// int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
//     vector<int> arr;
//     int i = 0, j = 0;

//     while (i < n && j < m) {
//         if (arr1[i] < arr2[j]) {
//             arr.push_back(arr1[i++]);
//         }
//         else {
//             arr.push_back(arr2[j++]);
//         }
//     }

//     while (i < n) {
//         arr.push_back(arr1[i++]);
//     }

//     while (j < m) {
//         arr.push_back(arr2[j++]);
//     }

//     return arr[k - 1];
    
// }