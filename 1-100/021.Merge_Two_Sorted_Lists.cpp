class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* end = head;
        
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                end->next = l1;
                end = end->next;
                l1 = l1->next;
            }
            else {
                end->next = l2;
                end= end->next;
                l2 = l2->next;
            }
        }
        
        if(l1 == NULL)
            end->next = l2;
        else
            end->next = l1;
        
        return head->next;
    }
};