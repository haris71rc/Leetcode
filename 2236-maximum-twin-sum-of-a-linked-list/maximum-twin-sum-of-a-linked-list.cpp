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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward;
        while(curr!=NULL){
            forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }   
public:
    int pairSum(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        temp=head;
        ListNode* prev = NULL;
        for(int i=0;i<size/2;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        ListNode* first = head;
        ListNode* second = reverse(temp);

        int sum=0;
        while(first!=NULL && second!=NULL){
            int a=first->val+second->val;
            sum=max(a,sum);
            first=first->next;
            second=second->next;
        }
        return sum;
    }
};