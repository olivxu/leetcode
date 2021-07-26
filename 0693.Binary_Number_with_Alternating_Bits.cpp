class Solution {
public:
    bool hasAlternatingBits(int n) {
        int num = n ^ (n >> 1);
        return isAllOnes(num);
    }
    
    // 写这个函数的必要性：因为（num & (num + 1)）== 0 会有溢出的问题
    bool isAllOnes(int num) { 
        while (num != 0) {
            if (num == ((num >> 1) << 1))
                return false;
            num = num >> 1;
        }
        return true;
    }
};