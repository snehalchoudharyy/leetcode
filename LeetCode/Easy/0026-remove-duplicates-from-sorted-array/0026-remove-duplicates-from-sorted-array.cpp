class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        map<int,int> freq;
        for(int j=0;j<n;j++){
            freq[nums[j]]++;
            if(freq[nums[j]]>1) continue;
            nums[i]=nums[j];
            i++;
        }
        return i;
    }
};