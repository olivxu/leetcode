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
    int curr_cnt = 0;
    int max_cnt = 0;
    int curr_mode = INT_MAX;
    vector<int> result;
    
    vector<int> findMode(TreeNode* root) {
        inOrderTraverse(root);
        return result;
    }
    
    void inOrderTraverse(TreeNode* curr) {
        if (curr == NULL)
            return;
        
        inOrderTraverse(curr->left);
        
        if (curr_cnt == 0) {
            curr_cnt = 1;
            curr_mode = curr->val;
            max_cnt = 1;
            result.push_back(curr_mode);
        }
        else {
            if (curr->val == curr_mode) {
                curr_cnt += 1;
                if (curr_cnt == max_cnt)
                    result.push_back(curr->val);
                if (curr_cnt > max_cnt) {
                    max_cnt = curr_cnt;
                    result.clear();
                    result.push_back(curr->val);
                }
            }
            else {
                curr_cnt = 1;
                curr_mode = curr->val;
                if (curr_cnt == max_cnt)
                    result.push_back(curr->val);
            }
        }
            
        
        inOrderTraverse(curr->right);
    }
};