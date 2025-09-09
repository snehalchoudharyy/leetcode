class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        int j=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){    //to find first zero in the array 
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1) return nums;  //if there is no zero in the array

        for (int i=j+1;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return nums;
    }
};