class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxSize = nums.size()/2;
        map<int, int> m;
        for (auto i : nums) {
            m[i]++;
        }
        int maxElem;
        for (auto i : m) {
            if (i.second > maxSize) {
                maxElem = i.first;
            }
        }
        return maxElem;
    }
};
