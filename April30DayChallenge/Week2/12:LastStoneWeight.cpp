class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        while(stones.size() > 1) {
            int y = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int x = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int diff = y-x;
            if (diff) {
                stones.push_back(diff);
                push_heap(stones.begin(), stones.end());
            }
        }
        if (stones.size() == 1) {
            return stones[0];
        }
        else return 0;
    }
};
