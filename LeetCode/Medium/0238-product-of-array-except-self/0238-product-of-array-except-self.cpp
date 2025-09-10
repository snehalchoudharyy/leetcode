class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int leftProduct=1;
        // first find result from left to right
        for(int i=0;i<n;i++){
            res[i]=leftProduct;
            leftProduct*=nums[i];
        }
        //now for right to left;
        int rightProduct=1;
        for(int i=n-1;i>=0;i--){
            res[i]=res[i]*rightProduct;
            rightProduct=rightProduct*nums[i];
        }

        return res;
    }
};