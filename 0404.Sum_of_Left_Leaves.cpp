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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int value = 0;
        if (root->left == NULL)
            return sumOfLeftLeaves(root->right); 
        else {
            if (root->left->left == NULL && root->left->right == NULL)
                value += root->left->val;
        }
        
        return value + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};