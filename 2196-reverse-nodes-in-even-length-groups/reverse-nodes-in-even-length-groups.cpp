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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        int group=1;
        ListNode* node = head;

        while(node != NULL && node->next != NULL){
            group++;

            int countNode = 0;
            ListNode* temp = node->next;
            while(temp!=NULL && countNode<group){
                temp=temp->next;
                countNode++;
            }

            if(countNode%2 == 0){
                ListNode* curr=node->next;
                ListNode* prev=NULL;
                ListNode* next=NULL;

                for(int i=0;i<countNode;i++){
                    next=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=next;
                }

                ListNode* tail = node->next;
                tail->next=curr;
                node->next=prev;
                node=tail;

            }
            else{
                for(int i=0;i<countNode;i++){
                    node=node->next;
                }
            }
        }
        return head;
    }
};