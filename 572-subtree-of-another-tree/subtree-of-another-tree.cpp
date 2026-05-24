class Solution {
private:
    bool findElement(TreeNode* root, TreeNode* subRoot){

    if(root == NULL) return false;

    if(root->val == subRoot->val){
        if(isSameTree(root,subRoot)){
            return true;
        }
    }

    bool left = findElement(root->left, subRoot);
    bool right = findElement(root->right, subRoot);

    return left||right;

}

bool isSameTree(TreeNode* p, TreeNode* q){

    if(p==NULL && q==NULL) return true;
    else if(p==NULL && q!=NULL) return false;
    else if(q==NULL && p!=NULL) return false;

    bool left = isSameTree(p->left,q->left);
    bool right = isSameTree(p->right,q->right);

    if(left && right && p->val == q->val) return true;
    else return false;
}
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return findElement(root,subRoot);
    }
};