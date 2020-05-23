class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector <vector<int>> ans;
        int i = 0, j = 0;
        while (i < A.size() and j < B.size()) {
            int lo = max(A[i][0], B[j][0]);
            int hi = min(A[i][1], B[j][1]);
            if (lo <= hi) ans.push_back({lo, hi});
            if (A[i][1] < B[j][1]) i++;
            else j++;
        }
        return ans;
    }
};
