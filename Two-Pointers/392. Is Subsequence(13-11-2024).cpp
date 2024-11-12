/*
Logic

1. Brute Force Approach:
a. The main idea is to check if the order of characters in string `s` is preserved in string `t`.
b. Iterate through `t` and compare each character with the current character in `s`.
c. If they match, increment the pointer for `s` to check the next character and move the `t` pointer forward.
d. If they do not match, move only the `t` pointer to continue the search.

Time Complexity: O(N)
Space Complexity: O(1)

2. Optimal Approach:
- The logic remains the same: use two pointers to efficiently check if `s` is a subsequence of `t`.

Time Complexity: O(N)
Space Complexity: O(1)
*/

bool isSubsequence(string s, string t) {
    if (t.size() < s.size()) return false;
    int sLeft = 0;
    int left = 0;
    
    while (sLeft < s.size() && left < t.size()) {
        if (s[sLeft] == t[left]) {
            sLeft++;  // Move the `s` pointer if characters match.
        }
        left++;  // Always move the `t` pointer.
    }
    
    return sLeft == s.size();  // Return true if all characters in `s` were matched.
}
