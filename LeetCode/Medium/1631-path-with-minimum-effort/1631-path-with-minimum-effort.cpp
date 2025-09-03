class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>> res(n,vector<int> (m,INT_MAX));
        res[0][0] = 0;
        using P=pair<int,pair<int,int>>; //to store difficulty and coordinates
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int d=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==m-1) return res[n-1][m-1];
            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];

                if(nr>=0&&nr<n &&nc>=0 &&nc<m ){
                    int diff=abs(heights[r][c]-heights[nr][nc]);
                    int newEffort=max(d,diff);
                    if(newEffort<res[nr][nc]){
                        res[nr][nc]=newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                    
                }
            }
        }
        return -1;
    }
};