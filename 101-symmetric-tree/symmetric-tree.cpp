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
    bool solve(TreeNode* r,TreeNode* l){
        if(r==NULL && l==NULL) return true;
        else if(r==NULL && l!=NULL) return false;
        else if(r!=NULL && l==NULL) return false;

        bool left=solve(r->left,l->right);
        bool right=solve(r->right,l->left);

        if(r->val==l->val && left && right) return true;
        else return false;
    }    
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return solve(root->left,root->right);
    }
};