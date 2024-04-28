class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%nums.size()]){  
                ++count;
            }
            if(count>1) return false;
        }
        return true;
    }
};

//Check whether previous element is smaller or not if bigger increase count and check for one more iteration again if next one is smaller then array is rotated otherwise not