class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> ans;
      if(root==NULL) return ans;
      queue<TreeNode*> q;
      bool leftToRight=true;
      q.push(root);
      while(!q.empty()){
        int size=q.size();
        vector<int> v(size);
        for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            q.pop();
            int index = leftToRight? i: size-i-1;
            v[index]=temp->val;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        leftToRight=!leftToRight;
        ans.push_back(v);
      }  
      return ans;
    }
};