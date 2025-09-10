class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long result=0;
        int i=0;
        while(i<n){
            int l=0;
            if(nums[i]==0){
                while(i<n && nums[i]==0){
                    l++;  //to find number of consecutive zero
                    i++;
                }
            }
            else i++;
            result+=(l)*(l+1)/2;

        }
        return result;
    }
};