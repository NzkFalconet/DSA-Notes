/*
Logic:

1. Brute Force Approach:

Time Complexity:
Space Complexity:

2. Optimal Approach:
a. Use two pointers: `currPntr` (current pointer) and `zeroPntr` (pointer for tracking the position to place non-zero elements).
b. If the current element is not zero, swap the current element with the element at the `zeroPntr` position.
c. After the swap, the `zeroPntr` now points to a non-zero element, so increment `zeroPntr` by 1.
d. Move the `currPntr` to the next position to continue checking.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPntr = 0; // Pointer for the position to place non-zero elements
        int curr = 0; // Pointer to traverse the array
        
        while (curr < nums.size()) {
            if (nums[curr] != 0) {
                // Swap the current element with the element at zeroPntr
                swap(nums[zeroPntr++], nums[curr]);
            }
            curr++;
        }
    }
};
