/*
 * 踩坑记录：最后一个节点也要记得reverse，连上前面的节点们
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = NULL;
        ListNode* currNode = head;
        ListNode* reversedHead = NULL;
        
        while (currNode != NULL) {
            ListNode* nextNode = currNode->next;
            
            // 当前节点是最后一个节点
            if (nextNode == NULL) {
                reversedHead = currNode;
            }
            
            // 无论是否是最后一个节点
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;     
        } 
        return reversedHead;
    }
};