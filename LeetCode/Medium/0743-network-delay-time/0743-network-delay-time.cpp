class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &e:times){
            adj[e[0]].push_back({e[1],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> res(n+1,INT_MAX);
        res[k]=0;
        int ans=INT_MIN;
        pq.push({0,k});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &[adjNode,wt]:adj[node]){
                if(d+wt<res[adjNode]){
                    res[adjNode]=d+wt;
                    pq.push({d+wt,adjNode});
                    ans=max(ans,d+wt);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(res[i]==INT_MAX){
                ans=-1;
            }
        }
        return ans;
    }
};