class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> res;
        map<int,int> mp; //to store index corresponding to values
        for(int i=0;i<n;i++){
            int a=nums[i];
            int b=target-a;
            if(mp.find(b)!=mp.end()){// if present in map push the index in result
                res.push_back(i);
                res.push_back(mp[b]);
            }
            mp[a]=i;  //if not present push the number as key in map and mapped with index as its value
        }
        return res;
    }
};