class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(auto e:prerequisites){
            adj[e[1]].push_back(e[0]);
        }
        vector<int> indegree(n,0);
        for(int u=0;u<n;u++){   //here assigning the indegree for each node
            for(auto v:adj[u]){
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){    //check for nodes having indegree zero
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto v:adj[node]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(cnt==n) return ans;
        return {};
        
    }
};