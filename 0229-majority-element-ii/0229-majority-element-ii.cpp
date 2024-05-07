class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        map<int,int> mpp;
        int min=(n/3)+1;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]==min){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};