class Solution {
public:
    int ans=0;
    int singleNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};