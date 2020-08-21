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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // case 1: both null
        if(!p && !q)
            return true;
        
        // case 2: only one is null
        else if((!p && q) || (p && !q))
            return false;
        
        // case 3: both not null, but value is different
        else if(p->val != q->val)
            return false;
        
        // case 4: both not null, value is same
        else
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};