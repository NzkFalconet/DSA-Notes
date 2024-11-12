/*
Logic 

1. Brute Force - (Two Pointers)

a. push all the elements from nums2 to nums1 and sort

TC - O(N*LogN) (Two pointers)
SC - O(LogN)
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for(int i = m;i<nums1.size();++i){
            nums1[i] = nums2[j++];
        }
        sort(nums1.begin(),nums1.end());
    }

/*
2. Optimal Approach - 

a. take two pointers one from m-1 and second from n-1
b. take right pointer which will eventaully push the element and will keep on reducing 

TC - O(N) (Two pointers)
SC - O(1)

*/ 


    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1;
        int p2 = n-1;
        int right = nums1.size()-1;
        while(p1>=0 && p2>=0){
            if(nums1[p1]>nums2[p2]){
                nums1[right--] = nums1[p1--];
            }else{
                nums1[right--] = nums2[p2--];
            }     
        }

        while(p1>=0){
           nums1[right--] = nums1[p1--];
        }
        while(p2>=0){
           nums1[right--] = nums2[p2--];
        }
    }
