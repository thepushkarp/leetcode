class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0) return 0;
        int lo = 0, mid = 0, ans = -1;
        int hi = citations.size() - 1;
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            if (citations[mid] == n - mid) {
                return n - mid;
            } else if (citations[mid] < n - mid) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        if (citations[lo] >= n - lo) {
            return n - lo;
        }
         
        if (citations[hi] >= n - hi) {
            return n - hi;
        }
        return 0;
    }
};

