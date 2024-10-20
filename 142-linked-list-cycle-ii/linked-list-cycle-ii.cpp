/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *fldc(ListNode *head){
        if(head==NULL) return NULL;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
           
            slow=slow->next;
            if(fast==slow){
                return slow;
            }
        }
        return NULL;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode * intersectionPoint=fldc(head);
        if(intersectionPoint==NULL) return NULL;
        ListNode *slow=head;
        while(slow!=intersectionPoint){
            slow=slow->next;
            intersectionPoint=intersectionPoint->next;
        }
        return slow;
    }
};