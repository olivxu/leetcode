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
    int min_diff = INT_MAX;
    TreeNode* prev = NULL;
    
    int getMinimumDifference(TreeNode* root) {
        inOrderTraverse(root);
        return min_diff;
    }
    
    void inOrderTraverse(TreeNode* curr) {
        if (curr == NULL)
            return;
        
        inOrderTraverse(curr->left);
        
        if (prev != NULL) 
            min_diff  = min(min_diff, abs(curr->val - prev->val));
        prev = curr;
        
        inOrderTraverse(curr->right);
    }
};