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
    ListNode* deleteDuplicates(ListNode* head) {
        ///vector<int> arr;

        int arr[300];
        ListNode* current = head;
        ListNode* prev = NULL;

        if(head==NULL) {
            return head;
        }

        //starting with adding the first value to the array and move node
        int len = 0;
        arr[len] = current->val;
        len++;
        prev = current;
        current = current->next;
    
        while(current!=NULL) {
            bool duplicateFound = false;
            for(int i=0;i<len;i++) {
                if(current->val==arr[i]) {
                    duplicateFound = true;
                    break;
                }
            }
            if(duplicateFound) {
                //delete the current node
                prev->next = current->next;
                current = current->next;
            } else {
                //add the val to the arr
                //len++
                arr[len]=current->val;
                len++;
                //move node
                prev = current;
                current = current->next;
            }
        }

        return head;
    }
};