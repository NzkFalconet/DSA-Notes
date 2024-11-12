/*
Logic

1. Brute Force Approach:
a. Sort both `ransomNote` and `magazine` strings.
b. Use two pointers: one for `ransomNote` and one for `magazine`.
c. If the current character in `ransomNote` matches the character in `magazine`, move both pointers forward.
d. If the current character in `magazine` does not match, move only the pointer for `magazine`.

Time Complexity: O(N * log N) (due to sorting)
Space Complexity: O(1)

2. Optimal Approach:
a. Store the frequency of each character in `magazine` using a hash map.
b. Traverse each character in `ransomNote` and check:
   - If the character is not in the map or its frequency is 0, return `false` (indicating the character is missing or insufficient).
   - Otherwise, decrement the frequency of the character in the map.
c. If all characters in `ransomNote` are found with sufficient frequency, return `true`.

Time Complexity: O(N)
Space Complexity: O(N) (due to the hash map)
*/


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        for(auto it:magazine)
            mp[it]++;
        
        for(auto it:ransomNote){
            if(!mp.count(it) || mp[it]==0)return 0;
            mp[it]--;
        }
        return 1;
    }
};