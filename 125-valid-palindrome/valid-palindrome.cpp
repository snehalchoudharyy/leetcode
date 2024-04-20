#include<bits/stdc++.h>
#include<iostream>
class Solution {
public:
    bool isPalindrome(string s) {
        string str,strlwr="";
        
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z'|| s[i]>='0' && s[i]<='9'){
                strlwr+=(char)tolower(s[i]);
            }
        }
        
            
    string orignalstr=strlwr;
    cout<<strlwr;
        int r=(strlwr.size());
        cout<<r;
        for(int i=0;i<(r);i++){
            
            swap(strlwr[i],strlwr[r-1]);
            r--;
        }
        if(orignalstr==strlwr){
                return true;
            }
            else{
                return false;
            }
            
    }    
};