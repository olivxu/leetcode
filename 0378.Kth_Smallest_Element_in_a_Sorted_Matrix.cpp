class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int> > que;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                que.push(matrix[i][j]);

        for (int i = 1; i <= k - 1; i++)
            que.pop();
        
        return que.top();
    }
};