class Trie {
private: 
    vector<Trie*> children = vector<Trie*>(26);
    int val;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        val = 0;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word, int val) {
        Trie* curr = this;
        int len = word.size();
        for (int i = 0; i < len; i++) {
            int index = word[i] - 'a';
            if (curr->children[index] == NULL)
                curr->children[index] = new Trie();
            curr = curr->children[index]; 
        }
        curr->val = val;
    }
    
    int sum(string prefix) {
        // 用层序遍历获得sum
        Trie* curr = this;
        int len = prefix.size();
        for (int i = 0; i < len; i++) {
            int index = prefix[i] - 'a';
            Trie* next = curr->children[index];
            if (next == NULL)
                return 0;
            else
                curr = next;
        }
        
        int sum = 0;
        queue<Trie*> que;
        que.push(curr);
        while (!que.empty()) {
            Trie* tmp = que.front();
            que.pop();
            sum += tmp->val;
            for (int i = 0; i < 26; i++) {
                if (tmp->children[i] != NULL)
                    que.push(tmp->children[i]);
            }
        }
        return sum;
    }
};

class MapSum {
private:
    Trie* trie;
public:
    /** Initialize your data structure here. */
    MapSum() {
        trie = new Trie();
    }
    
    void insert(string key, int val) {
        trie->insert(key, val);
    }
    
    int sum(string prefix) {
        return trie->sum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */