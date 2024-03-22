#include <bits/stdc++.h>

// Time complexity: O(n), Space complexity: O(1)
vector<int> rotateArray(vector<int> &arr, int n) {
  int temp = arr[0];
  for (int i = 1; i < n; i++) {
      arr[i - 1] = arr[i];
  }
  arr[n - 1] = temp;
  
  return arr;
}

// Time complexity: O(n), Space complexity: O(n)
// vector<int> rotateArray(vector<int> &arr, int n) {
//   vector<int> a(n);
//   for (int i = 0; i < n; i++) {
//     a[(i - 1 + n) % n] = arr[i];
//   }

//   return a;
// }
