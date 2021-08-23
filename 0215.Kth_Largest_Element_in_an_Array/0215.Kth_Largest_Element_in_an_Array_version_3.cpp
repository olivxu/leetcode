// 方法三：基于快速排序的快速选择

class Solution {
public:
    int quickSelect(vector<int> &nums, int begin, int end, int k) {
        int i = begin;
        int j = end;
        
        if (i < j) {
            int key = nums[i];
            while (i < j) {
                while (i < j && nums[j] > key)
                    j--;
                if (i < j) {
                    swap(nums[i], nums[j]);
                    i++;
                }
                while (i < j && nums[i] < key) 
                    i++;
                if (i < j) {
                    swap(nums[i], nums[j]);
                    j--;
                }
            }
            if (i == nums.size() - k)
                return key;
            else {
                if (i > nums.size() - k) 
                    return quickSelect(nums, begin, i - 1, k);
                else {
                    return quickSelect(nums, i + 1, end, k);
                }
            }
        }
        else return nums[i];
    }

    int findKthLargest(vector<int> &nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
    
};

