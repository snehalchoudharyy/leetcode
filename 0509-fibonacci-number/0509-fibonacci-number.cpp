#include<iostream>
#include<bits/stdc++.h>
class Solution {
public:
    int fib(int n) {
        int arr[31];
        arr[0]=0;
        arr[1]=1;
        for(int i=2;i<n;i++){
            arr[i]=arr[i-1]+arr[i-2];
        }
        if(n<2){
            return arr[n];
        }
        else{
            arr[n]=arr[n-1]+arr[n-2];
            return arr[n];
        }

        
    }   
};