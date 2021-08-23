class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
    vector<int> result;
    
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
        result.push_back(u);
        return;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        
        
        for (int i = 0; i < prerequisites.size(); i++) 
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        
        if (!valid)
            return {};
        
        reverse(result.begin(), result.end());
        return result;
    }
};