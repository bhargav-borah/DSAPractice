// int numberOfInversions(vector<int>&a, int n) {
//     int count = 0;
    
//     for (int i = 0; i < n - 1 ; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (a[i] > a[j]) count++;
//         }
//     }

//     return count;
// }
int merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    int count = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return count;
}

int mergeSort(vector<int>& arr, int low, int high) {
    int count = 0;
    if (low >= high) return count;
    int mid = (low + high) / 2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);

    return count;
}

int numberOfInversions(vector<int>&a, int n) {
    mergeSort(a, 0, n - 1);
}