class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(auto v:prerequisites){
            adj[v[1]].push_back(v[0]);
        }
        vector<int> indegree(n,0);
        for(int u=0;u<n;u++){
            for(auto v:adj[u]){
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }

        }
        if(cnt==n) return true;
        else return false;
    }
};