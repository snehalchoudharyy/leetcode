class Solution {
public:
    int hammingWeight(int n) {
        if(n==0) return 0;
        int cnt=0;
        while(n>1){
            if(n%2!=0){
            cnt++;
            }
            n=n/2;
        }
        return cnt+1;
        
    }
};