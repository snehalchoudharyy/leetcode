class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int longest=1;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto element:st){
            if(st.find(element-1)==st.end()){//check whether previous element is appearing in set if yes check for next element till we finds out the element whose previous element is not present
                int cnt=1;
                int x=element;
                while(st.find(x+1)!=st.end()){ //check for next consecutive element
                    x=x+1;
                    cnt=cnt+1;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};