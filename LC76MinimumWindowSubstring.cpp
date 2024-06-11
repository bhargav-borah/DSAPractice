class Solution {
public:

   string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    
    // Count characters in t
    for (char c : t) {
        need[c]++;
    }
    
    int left = 0, right = 0;
    int formed = 0; // Number of characters formed in the current window
    int required = need.size(); // Number of unique characters in t
    
    int min_length = INT_MAX;
    int min_window_start = 0;
    
    while (right < s.length()) {
        char c = s[right];
        
        // Add current character to the window
        window[c]++;
        
        // Check if current character satisfies the need
        if (need.count(c) && window[c] == need[c]) {
            formed++;
        }
        
        // Try to contract the window from the left
        while (formed == required && left <= right) {
            // Update the minimum window size
            int current_length = right - left + 1;
            if (current_length < min_length) {
                min_length = current_length;
                min_window_start = left;
            }
            
            // Remove the character at the left pointer from the window
            char left_char = s[left];
            window[left_char]--;
            
            // Check if removing this character affects the satisfaction of need
            if (need.count(left_char) && window[left_char] < need[left_char]) {
                formed--;
            }
            
            // Move left pointer to the right
            left++;
        }
        
        // Move right pointer to the right
        right++;
    }
    
    if (min_length == INT_MAX) {
        return "";
    } else {
        return s.substr(min_window_start, min_length);
    }
}
};