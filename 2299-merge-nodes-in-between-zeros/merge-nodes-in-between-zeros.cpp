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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* temp2=head;
        int sum=0;
        while(temp!=NULL){         
          if(temp->val==0){
            temp->val=sum;
            temp2->next=temp;
            temp2=temp;
            temp=temp->next;
            sum=0;
          }
          else{
            sum=sum+temp->val;
            temp=temp->next;
          }
        }
        return head->next;
    }
};