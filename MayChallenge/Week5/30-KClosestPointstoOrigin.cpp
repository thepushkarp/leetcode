class Solution {
public:
    static bool comparator(pair<int, int> f, pair<int, int> s) {
        return (f.second < s.second);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int, int>> distance;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            distance.push_back(make_pair(i, abs(x*x + y*y)));
        }
        sort(distance.begin(), distance.end(), comparator);
        vector<vector<int>> ans;
        for (int i = 0; i < K; i++) {
            vector<int> point;
            point.push_back(points[distance[i].first][0]);
            point.push_back(points[distance[i].first][1]);
            ans.push_back(point);
        }
        return ans;
    }
};
