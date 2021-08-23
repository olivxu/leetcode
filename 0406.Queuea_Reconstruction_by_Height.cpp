// 贪心
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int len = people.size();
        
        if (len <= 1)
            return people;
        
        // 身高降序，人数升序
        sort(people.begin(), people.end(), [](const auto &a, const auto &b){
            return (a[0] > b[0]) || (a[0] == b[0] && a[1] < b[1]);
        });
        
        vector<vector<int>> result;
        
        for (int i = 0; i < len; i++) {
            result.insert(result.begin() + people[i][1], people[i]);
        }
        
        return result;      
    }
};