class Solution {
public:
    void uniqueSubset(vector<int> nums,vector<vector<int>> &res,vector<int> ans){
        if(nums.size()==0){
            res.push_back(ans);
            return;
        }
        vector<int> op1=ans;
        vector<int> op2=ans;
        op2.push_back(nums[0]);
        nums.erase(nums.begin());
        uniqueSubset(nums,res,op1);
        uniqueSubset(nums,res,op2);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        uniqueSubset(nums,res,ans);
        return res;
    }
};