class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int small = 0;
        int large = len - 1;
        vector<int> result(2);
        
        while (small < large) {
            if (numbers[small] + numbers[large] == target) {
                result[0] = small + 1;
                result[1] = large + 1;
                break;
            }
            if (numbers[small] + numbers[large] > target) {
                large--;
            }
            if(numbers[small] + numbers[large] < target) {
                small++;
            }
        }
        return result;
    }
};