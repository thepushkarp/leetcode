class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int currMin = INT_MAX;
        int totMin = INT_MAX;
        int currMax = INT_MIN;
        int totMax = INT_MIN;
        int sum = 0;
        bool isPos = false;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > 0) {
                isPos = true;
                break;
            }
        }
        if (!isPos) {
            return *max_element(A.begin(), A.end());
        }
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            currMax = max(currMax, 0) + A[i];
            totMax = max(currMax, totMax);
            currMin = min(currMin, 0) + A[i];
            totMin = min(currMin, totMin);
        }
        return max(totMax, (sum - totMin));
    }
};
