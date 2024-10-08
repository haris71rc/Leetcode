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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*> s;
        while(!s.empty() || root){
            while(root){
                ans.push_back(root->val);
                s.push(root);
                root=root->right;
            }
            root=s.top();
            s.pop();
            root=root->left;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};