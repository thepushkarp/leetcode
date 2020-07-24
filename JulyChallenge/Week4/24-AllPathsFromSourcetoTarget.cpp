class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<vector<int>>& graph, int curr) {
        int n = graph.size() - 1;
        path.push_back(curr);
        if (curr == n) {
            ans.push_back(path);
        }
        else {
            for (auto node : graph[curr]) {
                dfs(graph, node);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return ans;
    }
};
