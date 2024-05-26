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
    void solve(TreeNode* root,map<int,TreeNode*> &m,int i){
        if(root==NULL) return;
        m[i]=root;
        // cout<<i<<" "<<m[i]->val<<endl;
        solve(root->left,m,i+1);
        solve(root->right,m,i+1);
    }    
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int,TreeNode*>m;
        vector<int> v;
        solve(root,m,0);
        for(auto i:m){
            v.push_back(i.second->val);
        }
        return v;
    }
};