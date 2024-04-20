#include<bits/stdc++.h>
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0;
        int r=s.size()-1;
        while(l<r){
            if(l>=r){
            return;
        }
        swap(s[l],s[r]);
        l++;
        r--;
        }
    }
};