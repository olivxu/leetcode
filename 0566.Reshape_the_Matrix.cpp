class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> result(r, vector<int> (c, 0));
        int m = mat.size();
        int n = mat[0].size();
        
        if (m * n != r * c) 
            return mat;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                result[i][j] = mat[(i*c + j) / n][(i*c + j) % n];
            }
        }
        return result;
    }
};