vector<int> superiorElements(vector<int>&a) {
    int n = a.size();

    vector<int> res;
    int maxi = a[n - 1];
    res.push_back(maxi);

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > maxi) {
            maxi = a[i];
            res.push_back(maxi);
        }
    }

    return res;
}

// Brute force solution
vector<int> superiorElements(vector<int>&a) {
    int n = a.size();
    vector<int> res;
    res.push_back(a[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        bool isSuperior = true;
        for (int j = i + 1; j < n; j++) {
            if (a[i] <= a[j]) {
                isSuperior = false;
                break;
            }
        }
        if (isSuperior) res.push_back(a[i]);
    }

    return res;
}
