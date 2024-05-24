class Solution {
private:
    int solve(TreeNode* root,int &maxi){
        if(root==NULL) return 0;

        int leftSum=max(0,solve(root->left,maxi));
        int rightSum=max(0,solve(root->right,maxi));
        maxi=max(maxi,root->val+leftSum+rightSum);
        return root->val+max(leftSum,rightSum);
    }    
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};