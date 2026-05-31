/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(vector<TreeNode*>& nums, int low, int high){
        if(low>high) return NULL;

        int mid = low + (high-low)/2;

        nums[mid]->left = solve(nums,low,mid-1);
        nums[mid]->right = solve(nums,mid+1,high);

        return nums[mid];
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<TreeNode*> v;
        if(head==NULL) return NULL;
        while(head!=NULL){
            v.push_back(new TreeNode(head->val));
            head=head->next;
        }
        return solve(v,0,v.size()-1);
    }
};