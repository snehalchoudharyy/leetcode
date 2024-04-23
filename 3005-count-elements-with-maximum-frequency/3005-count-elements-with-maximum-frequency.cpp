class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int count[101]={0};
        for(int x:nums){
            count[x]=count[x]+1;
        }
        int ans=0,max=-1;
        for(int x:count){
            if(max<x){
                max=x;
                ans=x;
            }
            else if(max==x){
                ans=ans+x;
            }
        }
        return ans;

        
    }
};