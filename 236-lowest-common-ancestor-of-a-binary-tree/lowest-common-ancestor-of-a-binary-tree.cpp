class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;

        TreeNode* leftt = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightt= lowestCommonAncestor(root->right,p,q);

        if(leftt!=NULL && rightt!=NULL) return root;
        else if(leftt!=NULL && rightt==NULL) return leftt;
        else if(leftt==NULL && rightt!=NULL) return rightt;
        else return NULL;
    }
};