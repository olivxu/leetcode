class Solution {
public:
    string addBinary(string a, string b) {
        int a_len = a.size();
        int b_len = b.size();
        
        // special case 1: a is empty
        if(!a_len)
            return b;
        // special case 2: b is empty
        if(!b_len)
            return a;
        
        // normal case:
        string result;
        int a_index = a_len - 1;
        int b_index = b_len - 1;
        int carry = 0;
        
        while(a_index >= 0 && b_index >= 0) {
            char tmp = a[a_index] + b[b_index] + carry - '0';
            if(tmp == '0') {
                result.insert(0, 1, '0');
                carry = 0;
            }
            else if(tmp == '1') {
                result.insert(0, 1, '1');
                carry = 0;
            }
            else if(tmp == '2') {
                result.insert(0, 1, '0');
                carry = 1;
            }
            else{ // tmp == '3';
                result.insert(0, 1, '1');
                carry = 1;
            }
            a_index--;
            b_index--;
        }
        
        while(a_index >= 0) {
            char tmp = a[a_index] + carry;
            if(tmp == '0') {
                result.insert(0, 1, '0');
                carry = 0;
            }
            else if(tmp == '1') {
                result.insert(0, 1, '1');
                carry = 0;
            }
            else { //tmp == '2'
                result.insert(0, 1, '0');
                carry = 1;
            }
            a_index--;
        }
        
        while(b_index >= 0) {
            char tmp = b[b_index] + carry;
            if(tmp == '0') {
                result.insert(0, 1, '0');
                carry = 0;
            }
            else if(tmp == '1') {
                result.insert(0, 1, '1');
                carry = 0;
            }
            else { //tmp == '2'
                result.insert(0, 1, '0');
                carry = 1;
            }
            b_index--;
        }
        
        if(carry) 
            result.insert(0, 1, '1');
        
        return result;
    }
};