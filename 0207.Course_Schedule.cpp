// 本题不需要使用拓扑排序，只需要检测有向图是否存在环即可. dfs

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
    
public:
    void dfs(int u) {
        visited[u] = 1;
        for (int i = 0; i < edges[u].size(); i++) {
            int v = edges[u][i];
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) 
                    return;
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
        return;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        
        
        for (int i = 0; i < prerequisites.size(); i++) 
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};


