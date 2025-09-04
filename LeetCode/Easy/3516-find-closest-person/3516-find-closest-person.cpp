class Solution {
public:
    int findClosest(int x, int y, int z) {
        int t1=abs(x-z);  //time taken by 1
        int t2=abs(y-z);   //time taken by 2
        if(t1>t2) return 2;
        else if(t2>t1) return 1;
        else return 0;
    }
};