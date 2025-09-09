class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minVal=INT_MAX;
       int profit=0;
       int n=prices.size();
       for(int i=0;i<n;i++){
        int price=prices[i];
        minVal=min(price,minVal);
        profit=max(profit,price-minVal);
       }
       
       return profit;
    }
};