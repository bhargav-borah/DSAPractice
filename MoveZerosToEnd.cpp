// Time complexity: O(n), Space complexity: O(1)
vector<int> moveZeros(int n, vector<int> a) {
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }
    if (j == -1) return a;

    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            j++;
        }
    }

    return a;
}

// Time complexity: O(n), Space complexity: O(n)
// vector<int> moveZeros(int n, vector<int> a) {
//     vector<int> nonZeros;
//     for (auto it: a) {
//         if (it != 0) nonZeros.push_back(it);
//     }

//     for (int i = 0; i < nonZeros.size(); i++) {
//         a[i] = nonZeros[i];
//     }

//     for (int i = nonZeros.size(); i < n; i++) {
//         a[i] = 0;
//     }

//     return a;
// }
