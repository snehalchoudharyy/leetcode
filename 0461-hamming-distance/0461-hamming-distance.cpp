class Solution {
public:
    int hammingDistance(int x, int y) {
        int pos=x^y;
        int cnt=0;
        while(pos>0){
            cnt=cnt+(pos&1);
            pos=pos>>1;
        }
        return cnt;
    }
};