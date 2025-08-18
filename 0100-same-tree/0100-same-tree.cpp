class Solution {
public:
    void traversal(TreeNode *root, vector<int> &v) {
        if(root == nullptr) {
            v.push_back(INT_MIN); // sentinel for null child
            return;
        }
        v.push_back(root->val);
        traversal(root->left, v);
        traversal(root->right, v);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> v1, v2;
        traversal(p, v1);
        traversal(q, v2);
        return v1 == v2;
    }
};
