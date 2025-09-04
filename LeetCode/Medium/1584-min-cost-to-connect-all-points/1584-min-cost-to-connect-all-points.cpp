class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        using P=pair<int,int>;
        vector<vector<P>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];

                int dist=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});

            }
        }
        vector<int> inMst(n,0);
        vector<int> parent(n,-1);
        int cost=0;
        using T=tuple<int,int,int>; //wt,node,parent
        priority_queue<T,vector<T>,greater<T>> pq;
        pq.push({0,0,-1});
        while(!pq.empty()){
            auto [wt,node,par]=pq.top();
            pq.pop();
            if(inMst[node]) continue; //if node visited check for next iteration
            inMst[node]=1;
            parent[node]=par;
            cost=cost+wt;
            for(auto [nextNode,nextCost]:adj[node]){
                if(!inMst[nextNode]){    //check that next node is not visited
                pq.push({nextCost,nextNode,node});

                }
            }
        }
        return cost;
    }
};