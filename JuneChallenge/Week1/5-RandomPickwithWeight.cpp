class Solution {
public:
    vector<int> weight;
    int total = 0;
    Solution(vector<int>& w) {
        srand(time(NULL));
        for (int i = 0; i < w.size(); i++) {
            total += w[i];
            weight.push_back(total);
        }
    }
    int pickIndex() {
        int ind = rand() % weight.back();
        return upper_bound(weight.begin(), weight.end(), ind) - weight.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
