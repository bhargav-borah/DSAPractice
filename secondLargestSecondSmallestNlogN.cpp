vector<int> getSecondOrderElements(int n, vector<int> a) {
    sort(a.begin(), a.end());
    return {a[n - 2], a[1]};
}
