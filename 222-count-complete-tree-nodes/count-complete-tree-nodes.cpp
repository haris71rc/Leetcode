class Solution {
private:
    int calculateHeight(TreeNode* node){
        int c=0;
        while(node){
            c++;
            node=node->left;
        }
        return c;
    }    
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int leftHeight=calculateHeight(root->left);
        int rightHeight=calculateHeight(root->right);
        if(leftHeight==rightHeight){
            return (1<<leftHeight) + countNodes(root->right);
        }
        else{
            return (1<<rightHeight) + countNodes(root->left);
        }
    }
};