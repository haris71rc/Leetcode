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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int size,int &index){
        if(start>end || index>=size) return NULL;
        TreeNode* root=new TreeNode(preorder[index]);
        int k=-1;
        for(int i=start;i<=end;i++){
            if(inorder[i]==preorder[index]) {
                k=i; 
                break;
                }
        }
        index++;
        root->left=solve(preorder,inorder,start,k-1,size,index);
        root->right=solve(preorder,inorder,k+1,end,size,index);

        return root;
    }    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        int n=preorder.size();
        return solve(preorder,inorder,0,n-1,n,index);
    }
};