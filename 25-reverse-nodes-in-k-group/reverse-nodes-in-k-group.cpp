class Solution {
public:
    ListNode* reverseIt(ListNode* head, int k) {
        int i = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (i < k) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return head;
        ListNode*curr=head;
        for (int i = 0; i < k; i++) {
            if (curr == NULL)
                return head;
            curr = curr->next;
        }
        
        ListNode* newHead= reverseIt(head,k);
        if(curr!=NULL){
            head->next = reverseKGroup(curr,k);
        }

        return newHead;
    }
};