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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int> &m,
                    int preStart, int preEnd, int inStart, int inEnd){
        if(preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot=m[root->val];
        int itemLeft=inRoot-inStart;

        root->left = solve(preorder,inorder,m,preStart+1,preStart+itemLeft,inStart,inRoot-1);
        root->right = solve(preorder,inorder,m,preStart+itemLeft+1,preEnd,inRoot+1,inEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return solve(preorder,inorder,m,0,preorder.size()-1,0,inorder.size()-1);
    }
};