class Solution {
public:
    int countDigits(int num) {
        string str = to_string(num);
        int cnt = 0;
        for(int i=0;i<str.length();i++){
            int val = str[i] - '0';
            if(num%val == 0){
                cnt += 1;
            }
        }
        return cnt;
    }
};