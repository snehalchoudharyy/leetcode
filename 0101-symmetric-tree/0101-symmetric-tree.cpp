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
    bool symmetryCheck(TreeNode* left,TreeNode* right){
        if(left==NULL ||right==NULL) return left==right;
        if(left->val!=right->val) return false;
        return symmetryCheck(left->left,right->right) &&symmetryCheck(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root==NULL ||symmetryCheck(root->left,root->right);
    }
};