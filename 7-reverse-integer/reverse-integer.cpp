class Solution {
public:
    int reverse(int x) {
         long reverse=0;
        while(x!=0){
            long int last=x%10;
            reverse=reverse*10 + last;
            x=x/10;
        }
        if(reverse > INT_MAX ||reverse <INT_MIN ){
            return 0;
        }
        return reverse;
    }
};