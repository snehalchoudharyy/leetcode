class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int j=n-1;
        int i=0;
        while(i<=j){
            if(nums[i]==val){
                swap(nums[i],nums[j]);
                j--;
            }
            else i++;
        }
    return i;
    }
    
};