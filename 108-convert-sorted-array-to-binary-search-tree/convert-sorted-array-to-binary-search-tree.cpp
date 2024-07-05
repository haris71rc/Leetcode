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
    TreeNode* solve(int high,int low,vector<int>& nums){
        if(low>high) return NULL;
        int mid = (low+high)/2;
        TreeNode* node=new TreeNode(nums[mid]);

        node->left = solve(mid-1,low,nums);
        node->right = solve(high,mid+1,nums);
        return node;
    } 
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root=solve(n-1,0,nums);
        return root;
    }
};