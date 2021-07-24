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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1;
        stack<int> stk2;
        stack<int> sum_stk;
        int carry = 0;
        
        while (l1 != NULL) {
            stk1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2 != NULL) {
            stk2.push(l2->val);
            l2 = l2->next;
        }
        
        while (!stk1.empty() && !stk2.empty()) {
            int num1 = stk1.top();
            int num2 = stk2.top();
            stk1.pop();
            stk2.pop();
            int sum = num1 + num2 + carry;
            sum_stk.push(sum % 10);
            carry = sum / 10;
        }
        
        while (!stk1.empty()) {
            int num = stk1.top();
            stk1.pop();
            int sum = num + carry;
            sum_stk.push(sum % 10);
            carry = sum / 10;
        }
        
        while (!stk2.empty()) {
            int num = stk2.top();
            stk2.pop();
            int sum = num + carry;
            sum_stk.push(sum % 10);
            carry = sum / 10;
        }
        
        if (carry != 0)
            sum_stk.push(carry);
        
        ListNode* result_head = new ListNode();
        ListNode* result_tail = result_head;        
        while (!sum_stk.empty()) {
            int num = sum_stk.top();
            sum_stk.pop();
            result_tail->next = new ListNode(num, NULL);
            result_tail = result_tail->next;
        }
        
        return result_head->next;
    }
};