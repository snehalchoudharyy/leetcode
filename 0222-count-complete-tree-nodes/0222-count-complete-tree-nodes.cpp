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
    void countNode(TreeNode* root,int &count){
        if(root->left==NULL && root->right==NULL){
            return;
        }
        if(root->left){
            count+=1;
            countNode(root->left,count);
        }
        if(root->right){
            count+=1;
            countNode(root->right,count);
        }
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int count=1;
        countNode(root,count);
        return count;
    }
};