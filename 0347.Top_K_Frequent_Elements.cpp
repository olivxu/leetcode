// 方法一： map + priority_queue + pair
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = nums.size();
         map<int, int> m;
        
        for (int i = 0; i < len; i++) {
            if (m.count(nums[i]) == 0)
                m[nums[i]] = 1;
            else
                m[nums[i]]++;
        }
        
        priority_queue<pair<int, int> > pq;
        
        map<int, int>::iterator iter = m.begin();
        while(iter != m.end()) {
            pq.push({iter->second, iter->first});
            iter++;
        }
        
        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = pq.top().second;
            pq.pop();
        }
        return result;
    }
};