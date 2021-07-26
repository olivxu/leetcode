class Solution {
public:
    int findComplement(int num) {
        int result;
        int i = 0;
        
        while (num != 0) {
            if ((num & 1) == 0)
                result = result | (1 << i);
            i++;
            num = num >> 1;
        }
        return result;
    }
};