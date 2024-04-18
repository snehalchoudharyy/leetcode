class Solution {
public:
    int countDigits(int n) {
        int count=0;
        int num=n;
        while(n!=0){
            int last=n%10;
            if(last==0){
                n=n/10;
                continue;
            }
            else if((num%last)==0){
                count++;
            }
            n=n/10;
        }
        return count;
        
    }
};