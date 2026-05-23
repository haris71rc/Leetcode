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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            vector<int> a;
            for (int i = 0; i < s; i++) {
                TreeNode* top = q.front();
                
                q.pop();
                if (top->left != NULL) {
                    q.push(top->left);
                }
                if (top->right != NULL) {
                    q.push(top->right);
                }
                a.push_back(top->val);
            }
            ans.push_back(a);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};