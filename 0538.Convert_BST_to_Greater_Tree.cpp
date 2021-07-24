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
    int sum = 0;
    
    TreeNode* convertBST(TreeNode* root) {
        convertBSTHelper(root);
        return root;
    }
    
    void convertBSTHelper(TreeNode* root) {
        if (root == NULL)
            return;
        
        // 先算右子
        if (root->right != NULL)
            convertBSTHelper(root->right);
        
        // 再算root
        sum += root->val;
        root->val = sum;
        
        // 最后算左子
        if (root->left != NULL)
            convertBSTHelper(root->left);
    }
};