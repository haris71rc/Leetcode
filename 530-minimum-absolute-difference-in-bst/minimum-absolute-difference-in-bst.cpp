class Solution {
private:
    void inOrderTraversal(TreeNode* root, int& prev, int& minDiff) {
        if (!root) return;

        // Traverse the left subtree
        inOrderTraversal(root->left, prev, minDiff);

        // Process the current node
        if (prev != -1) {
            minDiff = min(minDiff, root->val - prev);
        }
        prev = root->val;

        // Traverse the right subtree
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
