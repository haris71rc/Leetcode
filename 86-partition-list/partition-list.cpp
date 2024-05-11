class Solution {
private:
void InsertAtTail(ListNode* &head,ListNode* &tail, int d){
    if(tail == NULL){
        ListNode* newNode = new ListNode(d);
        tail = newNode;
        head = newNode;
    }else{
        ListNode* newNode = new ListNode(d);
        tail->next = newNode;
        tail = newNode;
    }
}

ListNode* PartitionList(ListNode* &mainhead, ListNode* &smallhead, ListNode* &smalltail, ListNode* &greathead, ListNode* &greattail, int val) {
    ListNode* temp = mainhead;
    while (temp != NULL) {
        if (temp->val < val) {
            InsertAtTail(smallhead, smalltail, temp->val);
        } else if (temp->val >= val) {
            InsertAtTail(greathead, greattail, temp->val);
        }
        temp = temp->next;
    }

    if (smallhead == NULL) {
        smallhead = greathead;
    } else {
        smalltail->next = greathead;
    }
    return smallhead;
}

public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* smallhead = NULL;
        ListNode* smalltail = NULL;
        ListNode* greathead = NULL;
        ListNode* greattail = NULL;

        ListNode* ans = PartitionList(head,smallhead,smalltail,greathead,greattail,x);
        
        return ans;
    }
};