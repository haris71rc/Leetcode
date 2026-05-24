class Solution {
private:
    void solve(TreeNode*& root) {
        if (root->left == NULL && root->right == NULL) {
            return;
        }

        invertTree(root->left);
        invertTree(root->right);

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL) return NULL;
        solve(root);
        return root;
    }
};