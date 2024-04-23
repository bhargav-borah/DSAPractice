int calculateDays(vector<int>& weights, int capacity) {
        int n = weights.size();
        int days = 1;
        int load = 0;

        for (int i = 0; i < n; i++) {
            if (load + weights[i] > capacity) {
                days++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (calculateDays(weights, mid) <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }

// int calculateDays(vector<int>& weights, int capacity) {
//         int n = weights.size();
//         int days = 1;
//         int load = 0;

//         for (int i = 0; i < weights.size(); i++) {
//             if (load + weights[i] > capacity) {
//                 days++;
//                 load = weights[i];
//             }
//             else {
//                 load += weights[i];
//             }
//         }

//         return days;
//     }

//     int shipWithinDays(vector<int>& weights, int days) {
//         int n = weights.size();
//         int low = *max_element(weights.begin(), weights.end());
//         int high = accumulate(weights.begin(), weights.end(), 0);

//         for (int i = low; i <= high; i++) {
//             int numDays = calculateDays(weights, i);
//             if (numDays <= days) return i;
//         }

//         return -1;
//     }
