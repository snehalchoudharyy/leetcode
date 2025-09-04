class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : flights){
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> minCost(n,INT_MAX);
        queue<pair<int,int>> q;
        minCost[src]=0;
        q.push({src,0});
        int stops=0;
        while(!q.empty() && stops<=k){
            int level=q.size();

            while(level--){
                int node=q.front().first;
                int cost=q.front().second;
                q.pop();
                for(auto [nbr,travelFare]:adj[node]){
                    if(cost+travelFare<minCost[nbr]){
                        minCost[nbr]=cost+travelFare;
                        q.push({nbr,cost+travelFare});
                    }
                }
            }
            stops++;
        }
        return minCost[dst]==INT_MAX?-1:minCost[dst];
    }
};
