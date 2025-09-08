class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char> charSet;
        int maxlen=0;
        int l=0;
        for(int r=0;r<n;r++){
            while(charSet.find(s[r])!=charSet.end()){
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
        
    }
};