// 方法一：堆，直接用priority_queue

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int len = nums.size();
        
        for (int i = 0; i < len; i++) 
            pq.push(nums[i]);
        
        for (int i = 0; i < k - 1; i++)
            pq.pop();
        
        return pq.top();
    }
};