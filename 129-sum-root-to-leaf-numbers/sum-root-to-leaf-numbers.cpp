class Solution {
private:
    void putInV(TreeNode* root,vector<int> &v,int digits){
        if(root->right==NULL && root->left==NULL){
            digits=digits*10+root->val;
            v.push_back(digits);
            return;
        }

        digits=digits*10+root->val;
        if(root->left){putInV(root->left,v,digits);}
        if(root->right){putInV(root->right,v,digits);}
        
    }    
public:
    int sumNumbers(TreeNode* root) {
        vector<int> v;
        putInV(root,v,0); 
        int sum=0;
        for(auto i:v){
            sum+=i;
        }      
        return sum;
    }
};