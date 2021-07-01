class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        int min_num = 1 << 30;
        int max_num = 0;
        
        for (int i = 0; i < length; i++) {
            min_num = min(min_num, prices[i]);
            max_num = max(max_num, prices[i] - min_num);
        }
        
        return max_num;
    }
};