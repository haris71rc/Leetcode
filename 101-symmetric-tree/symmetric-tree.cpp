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
    bool solve(TreeNode* l, TreeNode* r){
        if(l==NULL && r==NULL) return true;
        else if(l==NULL && r!=NULL) return false;
        else if(l!=NULL && r==NULL) return false;

        bool leftt = solve(l->left,r->right);
        bool rightt = solve(l->right,r->left);

        if(leftt && rightt && l->val == r->val) return true;
        else return false;

    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return solve(root->left,root->right);
        
    }
};