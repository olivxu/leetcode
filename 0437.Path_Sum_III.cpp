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
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;
        return countPathSum(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    
    int countPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;
        int cnt = 0;
        if (root->val == targetSum)
            cnt = 1;
        return cnt + countPathSum(root->left, targetSum - root->val) + countPathSum(root->right, targetSum - root->val);
    }
};