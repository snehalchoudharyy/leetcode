class Solution {
public:
    int maxFreqSum(string s) {
        int maxVowel=0;
        int maxCon=0;
        string vol="aeiou";
        int freq[26]={0};  //to count frequency
        for(auto &c:s){
            if(vol.find(c)!=string::npos){
                freq[c-'a']++;
                maxVowel=max(maxVowel,freq[c-'a']);
            }
            else{
                freq[c-'a']++;
                maxCon=max(maxCon,freq[c-'a']);
            }
        }
        return maxCon+maxVowel;

    }
};