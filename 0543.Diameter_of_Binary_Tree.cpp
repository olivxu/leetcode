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
    int diameter = 0; 
    
    int diameterOfBinaryTree(TreeNode* root) {
        recursively_compute_diameter(root);
        return diameter;
    }
    
    int recursively_compute_diameter(TreeNode* root) {
        // special case:
        if (root->left == NULL && root->right == NULL) 
            return 0;
        
        // normal case:
        int leftLen = (root->left == NULL) ? 0: recursively_compute_diameter(root->left) + 1;
        int rightLen = (root->right == NULL) ? 0: recursively_compute_diameter(root->right) + 1;
        diameter = max(diameter, leftLen + rightLen);
        
        return max(leftLen, rightLen);
    }
};