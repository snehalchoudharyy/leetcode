class Solution {
public:
    bool isPalindrome(int x) {
        long int rev=0;
        int num=x;

        while(x>0){
            int last = x%10;
            rev=rev*10+last;
            x=x/10;  
        }
        if(rev>INT_MAX || rev<INT_MIN){
            return 0;
        }
        if(rev==num){
            return true;
        }
        else{
            return false;
        }
    }
};