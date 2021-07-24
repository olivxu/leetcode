class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int len = arr.size();
        int max_num = 0;
        int cnt = 0;
        
        for(int i = 0; i < len; i++) {
            max_num = max(max_num, arr[i]);
            if (max_num == i)
                cnt++;
        }
        
        return cnt;
    }
};