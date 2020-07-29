class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int s = 0, cd = 0, h = INT_MIN;
        for (auto stock : prices) {
            int pS = s;
            int pCd = cd;
            int pH = h;
            cd = max(pCd, pS);
            s = pH + stock;
            h = max(pH, pCd - stock);
        }
        return max(cd, s);
    }
};
