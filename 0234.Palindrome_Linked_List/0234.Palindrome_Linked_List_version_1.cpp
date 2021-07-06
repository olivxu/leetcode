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
    bool isPalindrome(ListNode* head) {
        // special case:
        if (head == NULL || head->next == NULL)
            return true;
        
        // normal case:
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        
        // 先找中点
        while (fast) {
            slow = slow->next; 
            if (fast->next != NULL)
                fast = fast->next->next;
            else
                fast = NULL;
        }
        
        // 翻转后半张链表
        ListNode* curr = slow;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        ListNode* reversedHead = prev;
        
        // 比较两个链表
        // while循环终止条件是reversedHead是否null
        // 因为当链表长度为偶数，两半条链表的长度相等
        // 当链表长度为奇数，后半条链条比前半条链表短1
        while (reversedHead) {
            if (head->val != reversedHead->val)
                return false;
            head = head->next;
            reversedHead = reversedHead->next;
        }
        return true;
    }
};