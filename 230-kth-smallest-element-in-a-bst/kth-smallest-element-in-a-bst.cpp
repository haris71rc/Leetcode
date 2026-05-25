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
private:
    void solve(TreeNode* root, vector<int> &node){
        if(root==NULL) return;

        solve(root->left,node);
        node.push_back(root->val);
        solve(root->right,node);   
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> node;
        solve(root,node);
        return node[--k];
    }
};