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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* end = head;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            int tmp = 0;
            ListNode* newNode = new ListNode(0); 
            
            if (l1 != NULL)
                tmp += l1->val;
            if (l2 != NULL)
                tmp += l2->val;
            tmp += carry;
            carry = tmp / 10;
            
            newNode->val = tmp % 10;
            newNode->next = NULL;
            end->next = newNode;
            end = newNode;
            
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
        }
        
        return head->next;
    }
};