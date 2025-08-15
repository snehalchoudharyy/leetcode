class Solution {
public:
    void permutation(vector<int> &nums,int start,vector<vector<int>> &res){
        if(start==nums.size()-1){
            res.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int i=start;i<nums.size();i++){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
                swap(nums[start],nums[i]);
                permutation(nums,start+1,res);
                swap(nums[start],nums[i]);
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int start=0;
        vector<vector<int>> res;
        permutation(nums,start,res);
        return res;       
    }
};