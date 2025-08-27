class Solution {
public:
    void dfsfun(int node,vector<vector<int>> &adjLs,vector<int> &vis){
        vector<int> dfs;
        vis[node]=1;
        dfs.push_back(node);
        for(auto it:adjLs[node]){
            if(!vis[it]) dfsfun(it,adjLs,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        //converting matrix into list
        vector<vector<int>> adjLs(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfsfun(i,adjLs,vis);
            }
        }
        return cnt;

    }
};