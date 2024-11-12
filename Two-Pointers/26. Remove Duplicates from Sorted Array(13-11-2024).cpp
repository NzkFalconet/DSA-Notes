/*
Logic

1. Brute Force Approach (Two Pointers)

a. Add only unique elements to a temporary vector.
b. Replace the first `n` elements of `nums` with the elements in the temporary vector.

Time Complexity: O(N) (using an additional vector)
Space Complexity: O(N) (due to the temporary vector)
*/

int removeDuplicates(vector<int>& nums) {
        vector<int>temp;
        int left = 0;
        temp.push_back(nums[left++]);
        while(left<nums.size()){
            while(left<nums.size() && nums[left]==nums[left-1])left++;
            if(left==nums.size())break;
            temp.push_back(nums[left++]);
        }
        for(int i=0;i<temp.size();++i){
            nums[i] = temp[i];
        }
        return temp.size();
    }

/*
2. Optimal Approach

a. Use two pointers: both `pntr` and `left`, starting at index 1.
b. Increment `left` as long as `nums[left]` is equal to `nums[left - 1]`.
c. This ensures that duplicates are skipped.
d. Once `left` points to a unique element or reaches the end of the array, assign `nums[pntr]` to `nums[left]` and increment `pntr`.
e. Continue this process until `left` traverses the entire array.

Time Complexity: O(N) (using two pointers)
Space Complexity: O(1) (in-place modification)
*/



int removeDuplicates(vector<int>& nums) {
        int pntr = 1;
        int left = 1;
        while(left<nums.size()){
            while(left<nums.size() && nums[left]==nums[left-1])left++;
            if(left==nums.size())break;
            nums[pntr++] = nums[left++];
        }
        return pntr;
    }