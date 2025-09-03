class Solution {
public:
int shortestPathBinaryMatrix(vector<vector<int>>& grid){
    int n=grid.size();
    using P = pair<int, pair<int,int>>;
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<vector<int>> res(n,vector<int> (n,INT_MAX));
    if(grid[0][0]!=0) return -1;
    pq.push({0,{0,0}});
    grid[0][0]=1;
    res[0][0]=0;
    while(!pq.empty()){
        int d=pq.top().first;
        int row=pq.top().second.first;
        int col=pq.top().second.second;
        if(row==n-1 && col==n-1) return d+1;
        pq.pop();
        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int nr=row+delrow;
                int nc=col+delcol;
                if(nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]==0&&d+1<res[nr][nc] ){
                    res[nr][nc]=d+1;
                    pq.push({d+1,{nr,nc}});
                }
            }
        }

    }
    return -1;

}
};































//Using DFS

//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
//         vector<vector<int>> vis(n, vector<int>(n, 0));
//         queue<pair<int,int>> q;
//         q.push({0,0});
//         vis[0][0] = 1;
//         int cnt = 0;
//         while (!q.empty()) {
//             int sz = q.size();
//             cnt++;
//             while (sz--) {
//                 int row = q.front().first;
//                 int col = q.front().second;
//                 q.pop();
//                 if (row == n-1 && col == n-1) return cnt;
//                 for (int delrow=-1; delrow<=1; delrow++) {
//                     for (int delcol=-1; delcol<=1; delcol++) {
//                         int nr = row + delrow;
//                         int nc = col + delcol;
//                         if (nr>=0 && nr<n && nc>=0 && nc<n &&
//                             !vis[nr][nc] && grid[nr][nc]==0) {
//                             vis[nr][nc] = 1;
//                             q.push({nr,nc});
//                         }
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };
