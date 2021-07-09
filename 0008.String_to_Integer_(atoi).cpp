/*
 * 踩坑记录：
 * +-12 expect:0
 * 必须判断在读完【一个】+/-之后是不是数字
 */

class Solution {
public:
    int myAtoi(string s) {
        int pos_neg = 1;
        long result = 0;
        int len = s.size();
        int i = 0;
        
        // 消除 whitespace
        while (i < len && s[i] == ' ') 
            i++;
        
        // 如果此时已经读完了字符串，直接返回0
        if (i == len)
            return 0;
        
        // 读取正负
        if (s[i] == '+')
            i++;
        else if (s[i] == '-') {
            i++;
            pos_neg = -1;
        }
        
        // 判断此时字符串是否从数字开始
        if (s[i] < '0' || s[i] > '9')
            return 0;
            
        // 读取数字，直到遇到非数字的字符
        while (s[i] >= '0' && s[i] <= '9') {
            result = 10 * result + s[i] - '0';
            if (result >= INT_MAX && pos_neg > 0)
                return INT_MAX;
            else if (result * pos_neg <= INT_MIN && pos_neg < 0)
                return INT_MIN;
            i++;
        }
        return result * pos_neg;
    }
};