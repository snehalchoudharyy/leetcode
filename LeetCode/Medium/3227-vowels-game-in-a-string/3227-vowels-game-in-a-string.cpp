class Solution {
public:
    bool checkWinner(string s){
        vector<char> vol={'a','e','i','o','u'};
        int cnt=0;
        for(auto &c:s){
            if(find(vol.begin(),vol.end(),c)!=vol.end()){
                cnt++;
            }
        }
        return cnt>0;
    }
    bool doesAliceWin(string s) {
        if(checkWinner(s)) return true;
        return false;
    }
};