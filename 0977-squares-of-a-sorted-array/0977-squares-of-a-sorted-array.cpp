#include<bits/stdc++.h>
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int n=nums.size();
      vector<int> ans(n);
      int i=0;
      int j=n-1;
      int k=n-1;
      while(i<=j){
        if(abs(nums[i])<=abs(nums[j])){
            ans[k]=pow(nums[j],2);
            j--;
        } 
        else if(abs(nums[i])>abs(nums[j])){
            ans[k]=pow(nums[i],2);
            i++;
        }
        k--;
      }
      return ans;
    }
};