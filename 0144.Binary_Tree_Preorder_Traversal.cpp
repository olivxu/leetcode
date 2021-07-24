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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> result;
        
        if (root == NULL) 
            return result;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            result.push_back(curr->val);
            if (curr->right != NULL)
                stk.push(curr->right);
            if (curr->left != NULL)
                stk.push(curr->left);
        }
        
        return result;
    }
};