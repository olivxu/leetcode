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
    ListNode* oddEvenList(ListNode* head) {
        int odd = 1; // update every move
        ListNode* tail = head;
        int len = 0;
        
        while (tail != NULL && tail->next != NULL) {
            tail = tail->next;
            len++;
        }
        
        ListNode* curr = head;
        for (int i = 0; i < len; i += 2) {
            // 删除下一个node, 并移到最后
            ListNode* even = curr->next;
            if (even != NULL && even != tail) {
                ListNode* next_odd = even->next;
                even->next = NULL;
                curr->next = next_odd;
                tail->next = even;
                tail = tail->next;
                curr = curr->next;
            }
        }
        
        return head;
    }
};