class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N, vector<int>(N, 0));
        for (int i = 0; i < dislikes.size(); i++){
            graph[dislikes[i][0] - 1][dislikes[i][1] - 1] = 1;
            graph[dislikes[i][1] - 1][dislikes[i][0] - 1] = 1;
        }
        vector<int> col(N, -1);
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (col[i] == -1) {
                col[i] = 1;
                q.push(i);
                while(!q.empty()) {
                    int u = q.front();
                    if (graph[u][u] == 1) return false;
                    for (int v = 0; v < N; v++) {
                        if (graph[u][v] and col[v] == -1) {
                            col[v] = 1 - col[u]; 
                            q.push(v);
                        }
                        else if (graph[u][v] and col[v] == col[u]) 
                            return false; 
                    }
                    q.pop();
                }
            }
        }
        return true;
    }
};
