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
private:
    ListNode* reverse(ListNode* head, int k){
        if(head == NULL){
            return NULL;
        }
        ListNode* check=head;
        for(int i=0;i<k;i++){
            if(check==NULL) return head;
            check=check->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward;
        int count=0;

        while(curr!=NULL && count<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        if(curr!=NULL){
            head->next=reverse(curr,k);
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans=reverse(head,k);
        return ans;
    }
};