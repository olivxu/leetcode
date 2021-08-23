class Solution {
public:
    vector<int> partitionLabels(string s) {
        int len = s.size();
        vector<vector<int>> letter(26, vector<int> (2, -1));

        for (int i = 0; i < len; i++) {
            int index = s[i] - 'a';
            if (letter[index][0] == -1)
                letter[index][0] = i;
            letter[index][1] = i;
        }

        sort(letter.begin(), letter.end(), [](const auto &a, const auto &b){
            return a[0] < b[0];
        });

        vector<int> result;
        int i = 0;
        while (letter[i][0] == -1)
            i++;
        int right = letter[i][1];

        while (i < 26) {
            if (right < letter[i][0])
                result.push_back(right);
            right = max(right, letter[i][1]);
            i++;
        }
        result.push_back(right);

        for (int i = result.size() - 1; i > 0 ; i--)
            result[i] -= result[i - 1];
        result[0] += 1;

        return result;
    }
};