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
        ListNode* fast = head;
        ListNode* slow = head;

        bool cycle = false;

        while(fast!=NULL && fast->next!=NULL) {
            fast=fast->next->next;
            slow = slow->next;

            if(fast==slow) {
                cycle = true;
                break;
            }
        }

        if(!cycle) {
            return NULL;
            
        } 

        //find the node where the cycle begins
        slow = head;
        while(true) {
            if(slow==fast) {
                return slow;
            }
            fast=fast->next;
            slow=slow->next;
        }

    }
};