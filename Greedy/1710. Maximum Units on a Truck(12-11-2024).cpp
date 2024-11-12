/*
Logic 

1. Brute Force - 

a. Because we want to maximize number of units, we can sort array on the basis of number of units per box 
b. Then if truckSize is still greater than current number of boxes that means we can take all the boxes from current one. 
c. otherwise take remaining truckSize * numberOfUnitsPerBox; 

TC - O(N*logN) (Sorting array)
SC - O(LogN) (Sorting array)

2. Optimal Approach - Same as Brute Force

TC - O(N*logN) (Sorting array)
SC - O(LogN) (Sorting array)

*/ 


class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>&a,vector<int>&b){
            return a[1]>b[1];
        });
        int maxUnits =0;
        for(auto it:boxTypes){
           if(it[0]<truckSize){
            maxUnits+=(it[0]*it[1]);
            truckSize-=it[0];
           }else{
            maxUnits+=(truckSize*it[1]);
            break;
           }
        }
        return maxUnits;
    }
};