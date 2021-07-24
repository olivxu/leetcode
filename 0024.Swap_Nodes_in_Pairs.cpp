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
    ListNode* swapPairs(ListNode* head) {
        // special case:
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;
        
        // normal case:
        ListNode* prev = NULL;
        ListNode* curr1 = head;
        ListNode* curr2 = curr1->next;
        while (curr1 != NULL && curr1->next != NULL) {
            ListNode* curr2 = curr1->next;
            if (prev != NULL) {
                prev->next = swapPairsHelper(curr1, curr2);
                prev = prev->next->next;
                curr1 = prev->next;
            }
            else {
                head = swapPairsHelper(curr1, curr2);
                prev = head->next;
                curr1 = prev->next;
            }
        }
        return head;
    }
    
    ListNode* swapPairsHelper(ListNode* curr1, ListNode* curr2) {
        ListNode* next = curr2->next;
        curr1->next = next;
        curr2->next = curr1;
        return curr2;
    }
};