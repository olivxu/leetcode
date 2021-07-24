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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> que;
        
        if (root == NULL)
            return result;
        
        que.push(root);
        
        while (!que.empty()) {
            double sum = 0.0;
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) {
                TreeNode* curr = que.front();
                que.pop();
                sum += curr->val;
                if (curr->left != NULL)
                    que.push(curr->left);
                if (curr->right != NULL)
                    que.push(curr->right);
            }
            result.push_back(sum / double(cnt));
        }
        
        return result;
    }
};