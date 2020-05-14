class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int sum  = N*(N+1)/2;
        int trusts[N + 1], trustedBy[N + 1];
        for (int i = 1; i < N + 1; i++) {
            trusts[i] = 0;
            trustedBy[i] = 0;
        }
        for (int i = 0; i < trust.size(); i++) {
            trusts[trust[i][0]] += trust[i][1];
            trustedBy[trust[i][1]] += trust[i][0];
        }
        for (int i = 1; i < N + 1; i++) {
            if (trusts[i] == 0) {
                if (sum - trustedBy[i] == i) {
                    return i;
                }
            }
        }
        return -1;
    }
};
