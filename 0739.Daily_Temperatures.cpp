class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> result(len, 0);
        
        // special case:
        if (len == 1)
            return result;
        
        // normal case:
        // last day
        result[len - 1] = 0;
        
        // other days
        for (int i = len - 2; i >= 0; i--) {
            for (int j = i + 1; j < len; j += result[j]) {
                if (temperatures[i] < temperatures[j]) {
                    result[i] = j - i;
                    break;
                }
                if (temperatures[i] >= temperatures[j] && result[j] == 0) {
                    result[i] = 0;
                    break;
                }
            }
        }
        return result;
    }
};