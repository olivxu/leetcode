/* 三种解法：
 * 1. 数学方法：
 *    e.g. 1->2->2->1
 *    1 + 20 + 200 + 1000 == 1000 + 200 + 20 + 1
 *    问题：不通用，可能遇到过不了的case,链表里的数据不一定小于10，链表很长的时候，数据会溢出
 *    不推荐使用此方法
 * 2. 快慢指针 + 翻转链表：
 *    慢指针确定中点，翻转后半张链表，再比较两个链表
 *    翻转链表参考206题
 * 3. 递归：
 *    利用递归的栈的特性
 */

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
    ListNode* front;
    
    bool isPalindrome(ListNode* head) {
        // special case:
        if (head == NULL || head->next == NULL)
            return true;
        
        // normal case:
        front = head;
        return recursively_reverse_and_compare(head);
    }
    
    bool recursively_reverse_and_compare(ListNode* curr) {
        if (curr != NULL) {
            if (!recursively_reverse_and_compare(curr->next))
                return false;
            if (curr->val != front->val)
                return false;
            front = front->next;
        }
        return true;
    }
};