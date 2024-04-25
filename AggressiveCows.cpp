bool canWePlace(vector<int>& stalls, int k, int minDist) {
    int n = stalls.size();
    int prevCowIndex = -1;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            prevCowIndex = 0;
            k--;
        }
        else if (stalls[i] - stalls[prevCowIndex] >= minDist) {
            prevCowIndex = i;
            k--;
        }
        else continue;

        if (k == 0) return true;
    }

    return false;
}

int aggressiveCows(vector<int>& stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n - 1] - stalls[0];

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canWePlace(stalls, k, mid)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return high;
}

// bool canWePlace(vector<int>& stalls, int k, int minDist) {
//     int n = stalls.size();
//     int prevCowIndex = -1;

//     for (int i = 0; i < n; i++) {
//         if (i == 0) {
//             prevCowIndex = 0;
//             k--;
//         }
//         else if (stalls[i] - stalls[prevCowIndex] >= minDist) {
//             prevCowIndex = i;
//             k--;
//         }
//         else continue;

//         if (k == 0) return true;
//     }

//     return false;
// }

// int aggressiveCows(vector<int>& stalls, int k)
// {
//     int n = stalls.size();
//     sort(stalls.begin(), stalls.end());

//     int limit = stalls[n - 1] - stalls[0];

//     for (int i = 1; i <= limit; i++) { 
//         if (!canWePlace(stalls, k, i)) return i - 1; 
//     }

//     return limit;
// }

