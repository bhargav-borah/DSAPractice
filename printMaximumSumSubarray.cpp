void maximumSubarraySumPrint(vector<int> arr) {
    int maxi = INT_MIN;
    int sum = 0;
    
    int startIndex = -1;
    int endIndex = -1;
    
    for (int i = 0; i < arr.size(); i++) {
        if (sum == 0) startIndex = i;
        
        sum += arr[i];
        if (sum > maxi) {
            maxi = sum;
            endIndex = i;
        }
        
        if (sum < 0) sum = 0;
    }
    
    for (int i = startIndex; i <= endIndex; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}