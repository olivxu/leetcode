/*
 * solution: 层序遍历变种
 */
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
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* tmp;
        queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty()) {
            tmp = que.front();
            que.pop();
            if (tmp->right != NULL) 
                que.push(tmp->right);
            if (tmp->left != NULL)
                que.push(tmp->left);
        }
        
        return tmp->val;
    }
};