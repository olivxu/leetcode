class Solution {
public:
    bool isValid(string s) {
        stack<char> stack0;
        int length = s.size();
        
        for ( int i = 0; i < length; i++  ) {
            if ( stack0.size() == 0 )
                stack0.push(s[i]);
            else {
                if ( ( stack0.top() == '(' && s[i] == ')' ) 
                    || ( stack0.top() == '[' && s[i] == ']' ) 
                    || ( stack0.top() == '{' && s[i] == '}' ) ) 
                    stack0.pop();
                else 
                    stack0.push(s[i]);
            }
        }
        return stack0.size() == 0 ? true: false;
    }
};