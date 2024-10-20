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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            len=len+1;
        }
        
        cout<<len<<endl;
        int deleteNode=len-n;
        if(deleteNode==0) return head->next;
        len=0;
        ListNode* prev=NULL;
        temp=head;
        while(temp!=NULL && len<deleteNode){
            prev=temp;
            temp=temp->next;
            len++;
        }
        cout<<temp->val<<" "<<prev->val;
        prev->next=temp->next;
        temp->next=NULL;
        return head;
    }
};