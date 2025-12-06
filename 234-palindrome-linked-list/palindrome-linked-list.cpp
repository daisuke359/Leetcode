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
    bool isPalindrome(ListNode* head) {

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast!=NULL) {
            slow = slow->next;
        }

        //reverse the second half
        ListNode* current = slow;
        ListNode* prev = NULL;
        ListNode* next;

        while(current!=NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        while(prev!=NULL) {
            if(head->val != prev->val) {
                return false;
            }

            head = head->next;
            prev = prev->next;
        }

        return true;    
    }
};