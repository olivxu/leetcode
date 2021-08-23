// 贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 对于 [a, b, c, d]，如果有 a <= b <= c <= d ，
        // 那么最大收益为 d - a。而 d - a = (d - c) + (c - b) + (b - a) ，
        // 因此当访问到一个 prices[i] 且 prices[i] - prices[i-1] > 0，
        // 那么就把 prices[i] - prices[i-1] 添加到收益中。
        
        int len = prices.size();
        int profit = 0;
        for (int i = 1; i < len; i++) 
                profit += max(0, prices[i] - prices[i - 1]);
        
        return profit;
    }
};