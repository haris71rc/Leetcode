/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int data){
        Node* temp = new Node(data);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;

        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        Node* originalHead=head;
        Node* cloneKaHead=cloneHead;

        unordered_map<Node*,Node*>mapping;

        while(originalHead!=NULL){
            mapping[originalHead]=cloneKaHead;
            cloneKaHead=cloneKaHead->next;
            originalHead=originalHead->next;
        }
        originalHead=head;
        cloneKaHead=cloneHead;
        while(originalHead!=NULL){
            cloneKaHead->random=mapping[originalHead->random];
            cloneKaHead=cloneKaHead->next;
            originalHead=originalHead->next;
        }
        return cloneHead;
    }
};