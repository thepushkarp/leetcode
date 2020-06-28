class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (!n) return 0;
        int lo = 0, mid = 0, ans = 0;
        int hi = n - 1;
        while(lo <= hi){
            int mid  = lo + (hi - lo) / 2;
            if(citations[mid] >= n - mid){
                ans = n - mid;
                hi = mid - 1;
            }
            else{
                lo  = mid + 1;
            }
        }
        return ans;
    }
};
