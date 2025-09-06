class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            int a=nums[i];
            int more=target-a;
            if(mpp.find(more)!=mpp.end()){
                ans.push_back(mpp[more]);
                ans.push_back(i);
            }
            mpp[a]=i;
        }
        return ans;
    }
};