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
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr=head;
        stack<ListNode*> s;

        while(curr){
            while(!s.empty() && s.top()->val < curr->val){
                s.pop();
            }

            s.push(curr);
            curr=curr->next;
        }

        ListNode* next=NULL;
        while(!s.empty()){
            curr = s.top();
            s.pop();
            curr->next=next;
            next=curr;

        }

        return curr;
    }
};