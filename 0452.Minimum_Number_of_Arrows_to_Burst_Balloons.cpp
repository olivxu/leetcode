// 贪心
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0)
            return 0;
           
        sort(points.begin(), points.end(), [](const auto & a, const auto &b) {
            return a[0] < b[0];
        });
        
        int cnt = 1;
        int len = points.size();
        int right_range = points[0][1];
        int left_range = points[0][0];
              
        for (int i = 1; i < len; i++) {
            if (right_range < points[i][0]) {
                cnt++;
                right_range = points[i][1];
                left_range = points[i][0];
            }
            else {
                right_range = min(right_range, points[i][1]);
                left_range = points[i][0];
            }
        }
        
        return cnt;
    }
};