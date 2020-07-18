class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto i : prerequisites) {
            v[i[1]].push_back(i[0]);
            inDegree[i[0]]++;
        }
        vector<int> ans;
        queue<int> q;
        int count = 0;
        for (int i = 0; i < numCourses; i++) {
            if (!inDegree[i]) {
                q.push(i);
                count++;
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (auto i : v[curr]) {
                inDegree[i]--;
                if (!inDegree[i]) {
                    q.push(i);
                    count ++;
                }
            }
        }
        if (count == numCourses) {
            return ans;
        }
        else {
            return {};
        }
    }
};
