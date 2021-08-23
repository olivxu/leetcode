class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();

        int last = -2;
        int cnt = 0;
        
        for(int i = 0; i < len; i++) {
            if (i == len - 1 && flowerbed[i] == 0)
                cnt += (i - last) / 2;
            else if (flowerbed[i]) {
                cnt += (i - last - 2) / 2;
                last = i;
            }
        }
        
        return cnt >= n;
    }
};