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
    int cnt = 0;
    int result = -1;
    
    int kthSmallest(TreeNode* root, int k) {
        kthSmallestHelper(root, k);
        return result;
    }
    
    void kthSmallestHelper(TreeNode* root, int k) {
        if (root == NULL)
            return;
        if (root->left != NULL)
            kthSmallestHelper(root->left, k);
        cnt += 1;
        if(cnt == k)
            result = root->val;
        if (root->right != NULL)
            kthSmallestHelper(root->right, k);
    }
};