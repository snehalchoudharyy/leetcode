class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void unionFind(int x,int y){
        int x_parent=parent[x];
        int y_parent=parent[y];
        if(x_parent==y_parent) return;
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n,0);
        int e=connections.size();  //No. of edges
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        if(e<n-1) return -1;
        for(auto e:connections){
            int u=e[0];
            int v=e[1];
            if(find(u)!=find(v)) //find that parents are different for connected node
            {
                unionFind(u,v);
                 n=n-1;
            }
              //decrease number of components for every edge connection
        }
        return n-1;

    }
};