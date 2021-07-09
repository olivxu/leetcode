class Solution {
public:
    string multiply(string num1, string num2) {
        int carry = 0;
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> result(len1 + len2, 0);
        
        // special case:
        if (len1 == 1 && num1[0] == '0')
            return "0";
        if (len2 == 1 && num2[0] == '0')
            return "0";
        
        // normal case:
        for (int j = len2 - 1; j >= 0; j--) {
            for (int i = len1 - 1; i >= 0; i--) {
                int carry = result[i + j + 1];
                int tmp = (num1[i] - '0') * (num2[j] - '0') + carry;
                result[i + j + 1] = tmp % 10;
                result[i + j] += tmp / 10;
            }
        }
        
        // 除去前几位0
        int int_index = 0;
        int str_index = 0;
        string result_str;
        while (result[int_index] == 0)
            int_index++;
        
        while(int_index < len1 + len2) 
            result_str.insert(str_index++, to_string(result[int_index++]));
        
        return result_str;
    }
};