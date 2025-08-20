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
    void getPath(TreeNode *root,vector<string> &v,string s){
        if(!root) return;
        if (s.empty()) s += to_string(root->val);
        else s += "->" + to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            v.push_back(s);
            return;
        }
        getPath(root->left,v,s);
        getPath(root->right,v,s);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string s="";
        if(root==NULL) return v;
        getPath(root,v,s);
        return v;
    }
};