int getSecondLargest(vector<int> &a, int n) {
    int maxi = a[0];
    int secondLargest = INT_MIN;

    for (int i = 1; i < n; i++) {
        if (a[i] > maxi) {
            secondLargest = maxi;
            maxi = a[i];
        } else if (a[i] < maxi && a[i] > secondLargest) {
            secondLargest = a[i];
        }
    }

    return secondLargest;
}

int getSecondSmallest(vector<int> &a, int n) {
    int mini = a[0];
    int secondSmallest =  INT_MAX;

    for (int i = 1; i < n; i++) {
        if (a[i] < mini) {
            secondSmallest = mini;
            mini = a[i];
        } else if (a[i] > mini && a[i] < secondSmallest) {
            secondSmallest = a[i];
        }
    }

    return secondSmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int secondLargest = getSecondLargest(a, n);
    int secondSmallest = getSecondSmallest(a, n);

    return {secondLargest, secondSmallest};
}
