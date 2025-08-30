class Solution {
public:
    void dfskaro(int row,int col,vector<vector<int>>& grid,vector<vector<int>> &vis,int delrow[],int delcol[],int n,int m){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&!vis[nrow][ncol]&&grid[nrow][ncol]==1){
                dfskaro(nrow,ncol,grid,vis,delrow,delcol,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,+1,0,-1};
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++){   //to check 0 th and M-1 column
            if(!vis[i][0]&&grid[i][0]==1){
                dfskaro(i,0,grid,vis,delrow,delcol,n,m);
            }
            if(!vis[i][m-1]&&grid[i][m-1]==1){
                dfskaro(i,m-1,grid,vis,delrow,delcol,n,m);
            }
        }
        for(int j=0;j<m;j++){   //to check for 0th and N-1 row
            if(!vis[0][j]&&grid[0][j]==1){
                dfskaro(0,j,grid,vis,delrow,delcol,n,m);
            }
            if(!vis[n-1][j]&&grid[n-1][j]==1){
                dfskaro(n-1,j,grid,vis,delrow,delcol,n,m);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;

    }
};