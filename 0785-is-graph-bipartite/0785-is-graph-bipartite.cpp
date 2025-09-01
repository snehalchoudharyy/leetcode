class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int node,vector<int> &color,int currColor){
        color[node]=currColor;
        for(auto v:graph[node]){
            if(color[v]==color[node]){
                return false;
            }
            if(color[v]==-1){
                if(dfs(graph,v,color,1-currColor)==false) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        int currColor=0;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(graph,i,color,currColor)==false) return false;
            }
        }
        return true;
    }
};