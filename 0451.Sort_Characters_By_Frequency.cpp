// pair + priority_queue + map
class Solution {
public:
    string frequencySort(string s) {
        int len = s.size();
        map<char, int> m;

        for (int i = 0; i < len; i++) {
            if (m.count(s[i]) == 0)
                m[s[i]] = 1;
            else
                m[s[i]]++;
        }

        priority_queue<pair<int, char> > pq;

        map<char, int>::iterator iter = m.begin();
        int cnt = 0;
        while(iter != m.end()) {
            pq.push({iter->second, iter->first});
            iter++;
            cnt++;
        }

        string result;
        for (int i = 0; i < cnt; i++) {
            for(int j = 0; j < pq.top().first; j++)
                result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};