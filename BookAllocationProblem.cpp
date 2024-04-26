int getStudentsAllocated(vector<int>& arr, int maxPages) {
    int pages = 0;
    int countStudents = 1;

    for (int i = 0; i < arr.size(); i++) {
        if (pages + arr[i] > maxPages) {
            countStudents++;
            pages = arr[i];
        }
        else {
            pages += arr[i];
        }
    }

    return countStudents;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int studentsAllocated = getStudentsAllocated(arr, mid);
        if (studentsAllocated > m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

// int getStudentsAllocated(vector<int> arr, int maxPages) {
//     int pages = 0;
//     int studentCount = 1;

//     for (int i = 0; i < arr.size(); i++) {
//         if (pages + arr[i] > maxPages) {
//             pages = arr[i];
//             studentCount++;
//         }
//         else {
//             pages += arr[i];
//         }
//     }

//     return studentCount;
// }

// int findPages(vector<int>& arr, int n, int m) {
//     if (m > n) return -1;

//     int low = *max_element(arr.begin(), arr.end());
//     int high = accumulate(arr.begin(), arr.end(), 0);

//     for (int i = low; i <= high; i++) {
//         int studentsAllocated = getStudentsAllocated(arr, i);
//         if (studentsAllocated == m) return i;
//     }

//     return -1;
// }