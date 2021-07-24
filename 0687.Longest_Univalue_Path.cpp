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
    int max_path = 0;
    
    int longestUnivaluePath(TreeNode* root) {
        countPathLen(root);
        return max_path;
    }
    
    int countPathLen(TreeNode* root) {
        if (root == NULL)
                return 0;
        int left = countPathLen(root->left);
        int right = countPathLen(root->right);

        int leftPath = (root->left != NULL && root->val == root->left->val)? left + 1: 0;
        int rightPath = (root->right != NULL && root->val == root->right->val)? right + 1: 0;

        max_path = max(max_path, leftPath + rightPath);

        return max(leftPath, rightPath);
    }
    
};