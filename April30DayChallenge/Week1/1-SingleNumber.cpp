class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long ans = 0;
        for (auto i : nums) {
            ans^=i;
        }
        return ans;
    }
};
