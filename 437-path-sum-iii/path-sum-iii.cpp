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
    void solve(unordered_map<long long,int> m, int &count, long long currSum, TreeNode* root, int targetSum){
        if(root==NULL) return;

        currSum+=root->val;
        count+= m[currSum-targetSum];
        m[currSum]++;

        solve(m,count,currSum, root->left, targetSum);
        solve(m,count,currSum, root->right, targetSum);

        m[currSum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> m;
        m[0]=1;
        int count = 0;
        solve(m,count,0,root,targetSum);
        return count;
    }
};