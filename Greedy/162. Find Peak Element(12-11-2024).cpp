/*
Logic

1. Brute Force -

a. We can simply itterate through the array and find that element which is strictly greater than both of its neighbours.

TC - O(N)
SC - O(1)

2. Optimal Approach -

a. We can use binary search for this problem because there is always at least one peak element in the array.
b. For example, in the array [1, 2, 3, 4, 5], even though it is strictly increasing, we consider the elements beyond the first and last index as -∞. Therefore, 5 is a peak element.
c. We can start with two pointers: one at the beginning (0) and one at the end (nums.size() - 1) of the array.
d. Calculate the mid index. If the element at mid + 1 is greater than the element at mid, then mid + 1 could be a peak, so we move the left pointer to mid + 1.
e. Otherwise, we move the right pointer to mid, as mid might be a peak element.
f. The condition l < r is used because we are always checking mid against mid + 1.

TC - O(logN)
SC - O(1)

*/

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};