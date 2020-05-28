class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i <= num; i++) {
            if (i&1) {
                ans.push_back(ans[i-1] + 1);
            }
            else {
                ans.push_back(1 + ans[i - pow(2, floor((log(i)/log(2))))]);
            }
        }
        return ans;
    }
};
