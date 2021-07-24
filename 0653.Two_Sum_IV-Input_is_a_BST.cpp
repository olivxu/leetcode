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
    bool findTarget(TreeNode* root, int k) {
        // BFS + HashSet
        queue<TreeNode*> que;
        unordered_set<int> hashset;
        
        que.push(root);
        
        while (!que.empty()) {
            TreeNode* curr = que.front();
            int target = k - curr->val;
            if (hashset.count(target) != 0) 
                return true;
            hashset.insert(curr->val);
            que.pop();
            if (curr->left != NULL)
                que.push(curr->left);
            if(curr->right != NULL)
                que.push(curr->right);
        }
        return false;     
    }
};