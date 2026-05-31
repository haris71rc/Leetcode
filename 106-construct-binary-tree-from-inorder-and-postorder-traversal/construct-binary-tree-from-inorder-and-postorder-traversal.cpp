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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,unordered_map<int,int> &m,
                    int postStart, int postEnd, int inStart, int inEnd){
        if(postStart>postEnd || inStart>inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot=m[root->val];
        int itemLeft=inRoot-inStart;

        root->left = solve(postorder,inorder,m,postStart,postStart+itemLeft-1,inStart,inRoot-1);
        root->right = solve(postorder,inorder,m,postStart+itemLeft,postEnd-1,inRoot+1,inEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return solve(postorder,inorder,m,0,postorder.size()-1,0,inorder.size()-1);
    }
};