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
    void solve(TreeNode* root,vector<int> &in){
        if(root==NULL) return;
        solve(root->left,in);
        in.push_back(root->val);
        solve(root->right,in);
    }    
public:
    bool isValidBST(TreeNode* root) {
        vector<int> in;
        solve(root,in);
        for(int i=0;i<in.size()-1;i++){
            if(in[i]>=in[i+1]){
                return false;
            }
        }
        return true;
    }
};