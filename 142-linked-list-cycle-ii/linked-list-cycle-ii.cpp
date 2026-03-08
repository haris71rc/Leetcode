/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         ListNode* slow = head;
        ListNode* fast = head;
        ListNode* meetingNode = NULL;

        while (fast != NULL&& fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                meetingNode = slow;
                slow=head;
                break;
            }
        }
        if (meetingNode == NULL) {
            return meetingNode;
        } 

        while(meetingNode != slow){
            meetingNode = meetingNode->next;
            slow = slow->next;
        }

        return meetingNode;
    }
};