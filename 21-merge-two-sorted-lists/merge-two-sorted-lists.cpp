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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* first = list1;
        ListNode* second = list2;

        if(first==NULL) {
            return list2;
        } else if (second==NULL) {
            return list1;
        }

        
        //set the new head to the smaller head
        if(first->val < second->val) {
            head=first;
            first=first->next;
        }else {
            head=second;
            second=second->next;
        }

        ListNode* trail = head;
        while(first!=NULL && second!=NULL) {
            if(first->val < second->val) {
                trail->next = first;
                first = first->next;
            } else {
                trail->next = second;
                second = second->next;
            }
            trail = trail->next;

        }

        while(first!=NULL) {
            trail->next = first;
            first = first->next;
            trail = trail->next;
        }

        while(second!=NULL) {
            trail->next = second;
            second = second->next;
            trail = trail->next;
        }

        return head;
    }
};