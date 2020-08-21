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
        // special case 1: empty
        if(head == NULL)
            return head;
        
        // special case 2: there is only one node in the linked list
        if(head->next == NULL)
            return head;
        
        // normal case
        ListNode* tmp = head;
        while(tmp && tmp->next) {
            if(tmp->val == tmp->next->val) {
                ListNode* del = tmp->next;
                tmp->next = tmp->next->next;
                delete del;
            }
            else
                tmp = tmp->next;
        }
        
        return head;
    }
};