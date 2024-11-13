/*
Logic

1. Brute Force Approach:
a. In the brute force approach, we find all possible subsequences of length three from the array.
b. For each subsequence, we check if the condition nums[i] < nums[j] < nums[k] holds true.
c. If such a subsequence is found, we return true; otherwise, we return false.

Time Complexity: O(2^N) (due to recursive calls)
Space Complexity: O(N)

2. Optimal Approach:
a. We need to identify three indices i, j, and k such that i < j < k and nums[i] < nums[j] < nums[k].
b. We can maintain two variables: `firstMin` for the smallest number and `secondMin` for the second smallest number.
c. If we find a number larger than both `firstMin` and `secondMin`, we can confidently say that such a triplet exists and return true.
d. If no such triplet is found after traversing the array, we return false.

Time Complexity: O(N)
Space Complexity: O(1)
*/

bool increasingTriplet(vector<int>& nums) {
    int firstMin = INT_MAX, secondMin = INT_MAX;
    for (auto num : nums) {
        if (num <= firstMin) {
            firstMin = num;
        } else if (num <= secondMin) {
            secondMin = num;
        } else {
            return true;
        }
    }
    return false;
}
