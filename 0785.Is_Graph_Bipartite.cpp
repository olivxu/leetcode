class Solution {
private:
    static constexpr int UNCOLORED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // 广度优先搜索 + 着色
        int node_num = graph.size();
        vector<int> color(node_num, UNCOLORED);
        
        for (int i = 0; i < node_num; i++) {
            if (color[i] == UNCOLORED) {
                queue<int> que;
                que.push(i);
                color[i] = RED;
                while (!que.empty()) {
                    int node = que.front();
                    que.pop();
                    int neighbor_color = (color[node] == RED)? GREEN: RED;
                    for (int j = 0; j < graph[node].size(); j++) {
                        if (color[graph[node][j]] == UNCOLORED) {
                            color[graph[node][j]] = neighbor_color;
                            que.push(graph[node][j]);
                        }
                        else if (color[graph[node][j]] != neighbor_color) 
                            return false;
                    }
                }
            }
        }
        return true;
    }
};