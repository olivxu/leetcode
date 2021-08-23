class Solution {
public:
    int maxProduct(vector<string>& words) {
        // 利用位运算
        int len = words.size();
        vector<int> binary(len);
        int max_product = 0;
        
        for (int i = 0; i < len; i++)
            binary[i] = convertBinary(words[i]);
        
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if ((binary[i] & binary[j]) == 0) {
                    int product = words[i].size() * words[j].size();
                    max_product = max(max_product, product);
                }
            }
        }

        return max_product;
    }
    
    int convertBinary(string word) {
        int result = 0;
        int len = word.size();
        
        for (int i = 0; i < len; i++) 
            result = result | (1 << (word[i] - 'a'));
        
        return result;
    }
};