class Solution {
public:
    void dfs(vector<vector<int>> &image ,int row,int col,int n,int m,int oldcolor,int newcolor){
        if(row<0|| row>=n || col<0 || col>=m ||image[row][col]!=oldcolor){
            return;
        }
        image[row][col]=newcolor;
        dfs(image,row-1,col,n,m,oldcolor,newcolor);
        dfs(image,row,col+1,n,m,oldcolor,newcolor);
        dfs(image,row+1,col,n,m,oldcolor,newcolor);
        dfs(image,row,col-1,n,m,oldcolor,newcolor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int oldcolor=image[sr][sc];
        
        if(oldcolor==color){
            return image;
        }
        dfs(image,sr,sc,n,m,oldcolor,color);
        return image;

    }
};