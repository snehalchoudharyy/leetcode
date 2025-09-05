#include<bits/stdc++.h>
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
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent) return;
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[y_parent]>rank[x_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    int minCost(vector<vector<int>> &edges){
        int sum=0;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            
            int parent_u=find(u);
            int parent_v=find(v);
            if(parent_u!=parent_v){
                unionFind(u,v);
                sum=sum+wt;
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        using T=tuple<int,int,int>;
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];

                int dist=abs(x1-x2)+abs(y1-y2);
                edges.push_back({i,j,dist});
            }
        }
        sort(edges.begin(),edges.end(),[](vector<int> &a,vector<int>&b){
            return a[2]<b[2];
        });
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        rank.resize(n,0);
        return minCost(edges);
    }
};