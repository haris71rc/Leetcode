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
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder,unordered_map<int,int> m,
                    int prestart,int prend,int poststart,int postend){
        if(prestart>prend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
         if(prestart==prend) return root;

        int index = m[preorder[prestart+1]];
        int itemLeft = index - poststart + 1;

        root->left = solve(preorder,postorder,m,prestart+1,prestart+itemLeft,poststart,index);
        root->right = solve(preorder,postorder,m,prestart+itemLeft+1,prend,index+1,postend-1);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i=0;i<postorder.size();i++){
            m[postorder[i]]=i;
        }

        return solve(preorder,postorder,m,0,preorder.size()-1,0,postorder.size()-1);
    }
};