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
    void createMap(vector<int>& inorder,int n,map<int,int> &m){

        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int start,int end,int &index,int size,map<int,int> &m){
        if(index<0 || start>end) return NULL;
        TreeNode* root=new TreeNode(postorder[index]);
        int k=m[postorder[index]];
    
        index--;
        root->right=solve(inorder,postorder,k+1,end,index,size,m);
        root->left=solve(inorder,postorder,start,k-1,index,size,m);
        
        return root;
    }    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int index=n-1;
        map<int,int>m;
        createMap(inorder,n,m);
        return solve(inorder,postorder,0,n-1,index,n,m);
    }
};