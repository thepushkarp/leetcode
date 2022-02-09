class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> g(numCourses);
        int visited = 0;
        for (auto pre : prerequisites) {
            g[pre[0]].push_back(pre[1]);
            inDegree[pre[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            visited++;
            for (int i = 0; i < g[v].size(); i++) {
                if (inDegree[g[v][i]] == 1){
                    inDegree[g[v][i]]--;
                    q.push(g[v][i]);
                }
                else if (inDegree[g[v][i]] > 1) {
                    inDegree[g[v][i]]--;
                }
            }
        }
        return visited == numCourses;
    }
};
