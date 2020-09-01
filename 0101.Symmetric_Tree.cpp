/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // special case
        if(!root)
            return true;
        
        // normal case
        queue<TreeNode*> que;
        que.push(root);
        que.push(root);
        while(!que.empty()) {
            TreeNode* t1 = que.front();
            que.pop();
            TreeNode* t2 = que.front();
            que.pop();
            
            if(!t1 && !t2)
                continue;
            else if(!t1 || !t2)
                return false;
            else if(t1->val != t2->val)
                return false;
            else {
                que.push(t1->left);
                que.push(t2->right);
                que.push(t1->right);
                que.push(t2->left);
            } 
        }
        return true;
    }
};