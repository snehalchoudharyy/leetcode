class Solution {
public:
    int maximum69Number (int num) {
        vector<int> v;
        int digit;
        while(num>0){
            digit=num%10;
            v.push_back(digit);
            num=num/10;
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(v[i]==6){
                v[i]=9;
                break;
            }
        }
        int single=0;
        for(int digit:v) single=single*10+digit;
        return single;
    }
};