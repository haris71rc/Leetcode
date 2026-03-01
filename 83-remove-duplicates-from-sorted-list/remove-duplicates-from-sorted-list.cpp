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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        if(head->next== NULL){
            return head;
        }
         

        ListNode* curr = head;
        ListNode* nextt = head->next;

        while(nextt!=NULL){
            if(curr->val==nextt->val){
                curr->next=nextt->next;
            }
            else{
               curr=nextt; 
            }
            nextt=nextt->next;
        }
        return head;
    }
};