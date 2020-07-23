class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto i : nums) {
            x ^= i;
        }
        int rightBit = (x) & ~(x-1);
        int a = 0, b = 0;
        for (auto i : nums) {
            if (i & rightBit) {
                a ^= i;
            }
            else {
                b ^= i;
            }
        }
        return {a, b};
    }
};
