class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x==parent[x]) return x;
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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(string s:equations){   //first do union of ==
            if(s[1]=='='){ //if(a==b) it means its 1 index is = in == case
                unionFind(s[0]-'a',s[3]-'a'); //convert char to int
            }
        }
        for(string s:equations){
            if(s[1]=='!'){   //in a!=b case

                int first=find(s[0]-'a');
                int third=find(s[3]-'a');
                if(first==third) return false;
            }
        }
        return true;
    }
};