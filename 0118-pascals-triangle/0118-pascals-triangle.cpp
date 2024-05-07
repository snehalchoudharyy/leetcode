class Solution {
public:
    vector<int> generateRow(int row){
        //this function takes the row number and generate the entire row
        long long ans=1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col=1;col<row;col++){
            ans=ans*(row-col);
            ans=ans/(col);
            ansRow.push_back(ans);
        }
        return ansRow;

    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int n=numRows;
        for(int i=1;i<=n;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};