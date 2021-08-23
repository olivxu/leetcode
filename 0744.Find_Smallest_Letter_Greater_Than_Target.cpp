// 方法二：二分法
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        int left = 0;
        int right = len;
        int mid = (left + right) / 2;
        
        while (left < right) {
            mid = (left + right) / 2;
            if (letters[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        
        return letters[left % len];
    }
};