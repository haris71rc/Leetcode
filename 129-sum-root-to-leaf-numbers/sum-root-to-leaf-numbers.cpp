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
    void solve(TreeNode* root,int &count,int currSum){
        if(root==NULL) return;
        currSum = currSum*10 + root->val;
        if(root->left==NULL && root->right==NULL){
            count+=currSum;
        }

        solve(root->left, count, currSum);
        solve(root->right, count, currSum);

        currSum-=root->val;
    }
public:
    int sumNumbers(TreeNode* root) {
        int count=0;
        solve(root,count,0);
        return count;
    }
};