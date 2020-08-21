class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        int carry = 0;
        
        digits[length - 1] += 1;
        
        for(int i = length - 1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        
        if(carry) 
            digits.insert(digits.begin(), carry);
        
        return digits;
    }
};