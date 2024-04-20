int floorSqrt(int n) {
    if (n == 0 || n == 1) return n;

    int low = 1, high = n ;
    int res = 1;

    while (low <= high) {
        long mid = low + (high - low) / 2;
        long squareVal = mid * mid;
        if (squareVal == (long long)n) return mid;
        else if (squareVal > n) high = mid - 1;
        else if (squareVal < n) {
            res = mid;
            low = mid + 1;
        }
    }
    
    return res;
}
