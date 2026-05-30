/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void doInorder(TreeNode* root, vector<TreeNode*>& inOrder) {
        if (root == NULL)
            return;

        doInorder(root->left, inOrder);
        inOrder.push_back(root);
        doInorder(root->right, inOrder);
    }

public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inOrder;
        doInorder(root, inOrder);

        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        for (int i = 0; i < inOrder.size() - 1; i++) {
            if (inOrder[i]->val > inOrder[i + 1]->val) {

                if (first == nullptr) {
                    first = inOrder[i];
                }

                second = inOrder[i + 1];
            }
        }

        swap(first->val, second->val);

        return;
    }
};