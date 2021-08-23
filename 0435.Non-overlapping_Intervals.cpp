// 贪心法： 
// 按区间最右排序后，每次选择左侧不和前一个右侧重合的，
// 得到不重合的区间数，len-不重合=需要remove的个数
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) 
            return 0;
        
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        
        int right = intervals[0][1];
        int len = intervals.size();
        int cnt = 1;
        
        for (int i = 1; i < len; i++) {
            if (intervals[i][0] >= right) {
                cnt++;
                right = intervals[i][1];
            }
        }
        return len - cnt;
    }
};