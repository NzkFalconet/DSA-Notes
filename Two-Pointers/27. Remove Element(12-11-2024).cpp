/*
Logic 

1. Brute Force - (Two Pointers)

a. We dont need to delete elements or use another array to return elements which are not equal to val
b. so we can use two pointer left, right.
c. left will start from 0 and right will start from last index
d. when we encounter element equal to target element, we simply put this element to right most side and 
move right pointer to one close position because that position is now occupied by target equal element
d. now we'll again check if current element is equal or not to target value. if not we will move left to +1 position and increase our size counter to +1;

TC - O(N) (Two pointers)
SC - O(1)

2. Optimal Approach - Same as Brute Force

TC - O(N) (Two pointers)
SC - O(1)

*/ 

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right = nums.size()-1;
        int left = 0;
        while(left<=right){
            if(nums[left]==val){
                swap(nums[left],nums[right--]);
            }else{
                left++;
            }
        }
        return left;
    }
};