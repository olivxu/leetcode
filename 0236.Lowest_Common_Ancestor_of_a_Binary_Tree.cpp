/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* result;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return result;
    }
    
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return false;
        
        // 在当前node
        bool inCurrent = (root->val == p->val || root->val == q->val);
        
        // 在左子树中
        bool inLeft = dfs(root->left, p, q);
        
        // 在右子树中
        bool inRight = dfs(root->right, p, q);
        
        if ((inLeft && inRight) || (inCurrent && (inLeft || inRight)))
            result = root;
        
        return inCurrent || inLeft || inRight;
    }
};