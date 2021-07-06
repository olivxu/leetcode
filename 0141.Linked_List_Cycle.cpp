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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast != NULL) {
            slow = slow->next;
            if (fast->next != NULL) 
                fast = fast->next->next;
            else
                return false;
            if (fast == slow)
                return true;
        }
        return false;
    }
};