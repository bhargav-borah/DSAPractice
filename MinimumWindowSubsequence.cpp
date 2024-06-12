bool isSubsequence(const string& S, const string& T, int start, int end) {
    int tIndex = 0;
    for (int i = start; i <= end && tIndex < T.size(); ++i) {
        if (S[i] == T[tIndex]) {
            tIndex++;
        }
    }
    return tIndex == T.size();
}

string minWindowSubsequence(string S, string T) {
    int n = S.size();
    int m = T.size();
    int minLength = INT_MAX;
    int minStart = -1;

    for (int start = 0; start < n; ++start) {
        for (int end = start; end < n; ++end) {
            if (isSubsequence(S, T, start, end)) {
                if (end - start + 1 < minLength) {
                    minLength = end - start + 1;
                    minStart = start;
                }
                break; // No need to check further as we found a valid window
            }
        }
    }

    if (minStart == -1) {
        return "";
    } else {
        return S.substr(minStart, minLength);
    }
}