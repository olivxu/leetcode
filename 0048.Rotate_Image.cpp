class Solution {
public:
    // 此处涉及的下标区间都是左闭右开
    void rotate(vector<vector<int>>& matrix) {
        int matrix_size = matrix.size();
        recursively_rotate(matrix, 0, matrix_size - 1);
    }
    
    void recursively_rotate(vector<vector<int>>& matrix, int start, int end) {
        if (start >= end) {
            return;
        }
        
        for (int i = 0; i < end - start; i++) {
            int tmp = matrix[start][start + i];
            matrix[start][start + i] = matrix[end - i][start];
            matrix[end - i][start] = matrix[end][end - i];
            matrix[end][end - i] = matrix[start + i][end];
            matrix[start + i][end] = tmp;
        }
        recursively_rotate(matrix, start + 1, end - 1);
    }
    
    
};