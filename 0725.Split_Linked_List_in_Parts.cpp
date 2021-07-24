vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k);
        int len = 0;
        
        ListNode* curr = head;
        while (curr != NULL) {
            len++;
            curr = curr->next;
        }
        
        int i = 0;
        int j = 0;
        ListNode* subHead = head;
        
        while (j < len) {
            int sublen = ceil(double(len - j) / double(k));
            
            ListNode* subTail = subHead;
            for (int a = 0; a < sublen - 1; a++) {
                subTail = subTail->next;
            }
            ListNode* nextHead = subTail->next;
            subTail->next = NULL;
            result[i] = subHead;
            
            // update i,j, subHead
            i++;
            j += sublen;
            k--;
            subHead = nextHead;
        }
        
        return result;      
    }