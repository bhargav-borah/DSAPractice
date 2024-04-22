bool isPossible(vector<int>& bloomDay, int day, int m, int k) {
        int n = bloomDay.size();
        int count = 0;
        int numBouquets = 0;

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                count++;
            }
            else {
                numBouquets += (count / k);
                count = 0;
            }
        }
        numBouquets += (count / k);

        return numBouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n / k < m) return -1;

        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++) {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(bloomDay, mid, m, k)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }

    // int minDays(vector<int>& bloomDay, int m, int k) {
    //     int n = bloomDay.size();

    //     int low = INT_MAX, high = INT_MIN;
    //     for (int i = 0; i < n; i++) {
    //         low = min(low, bloomDay[i]);
    //         high = max(high, bloomDay[i]);
    //     }

    //     for (int i = low; i <= high; i++) {
    //         if (isPossible(bloomDay, i, m, k)) return i;
    //     }

    //     return -1;
    // }