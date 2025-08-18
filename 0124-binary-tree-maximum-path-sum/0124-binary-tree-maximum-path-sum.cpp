/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
        int lsum=maxSum(root->left,maxi);
        int rsum=maxSum(root->right,maxi);
        maxi=max(maxi,root->val+lsum+rsum);
        return root->val+lsum+rsum;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=0;
        maxSum(root,maxi);
        return maxi;
    }
};