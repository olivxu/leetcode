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
    int rob(TreeNode* root) {
        // i = 0 偷， i = 1 不偷
        vector<int> amount = recursively_rob(root);
        return max(amount[0], amount[1]);
    }
    
    vector<int> recursively_rob(TreeNode* curr) {
        vector<int> amount(2, 0);
        
        if (curr != NULL) {
            vector<int> left_amount = recursively_rob(curr->left);
            vector<int> right_amount = recursively_rob(curr->right);
            amount[0] = left_amount[1] + right_amount[1] + curr->val;
            amount[1] = max(left_amount[0], left_amount[1]) + max(right_amount[0], right_amount[1]);
        }
        return amount;
    }
};