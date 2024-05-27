class Solution {
private:
    void inOrderTraversal(TreeNode* root, int& prev, int& minDiff) {
        if (!root) return;

        inOrderTraversal(root->left, prev, minDiff);

        if (prev != -1) {
            minDiff = min(minDiff, root->val - prev);
            //cout<<"root Val "<<root->val<<" "<<"prev "<<prev<<" mindiff "<<minDiff<<endl;
        }
        prev = root->val;
        //cout<<prev<<endl;

        inOrderTraversal(root->right, prev, minDiff);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        int minDiff = INT_MAX;
        inOrderTraversal(root, prev, minDiff);
        return minDiff;
    }
};
