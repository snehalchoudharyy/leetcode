class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        int x=start^goal;
        while(x>0){
            cnt=cnt+(x&1);
            x=x>>1;
        }
        return cnt;
    }
};