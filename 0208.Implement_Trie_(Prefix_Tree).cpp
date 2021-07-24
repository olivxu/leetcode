class Trie {
private: 
    vector<Trie*> children = vector<Trie*>(26);
    bool isLeaf;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        isLeaf = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr = this;
        int len = word.size();
        for (int i = 0; i < len; i++) {
            int index = word[i] - 'a';
            if (curr->children[index] == NULL)
                curr->children[index] = new Trie();
            curr = curr->children[index];
        }
        curr->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* curr = this;
        int len = word.size();
        for (int i = 0; i < len; i++) {
            int index = word[i] - 'a';
            Trie* next = curr->children[index];
            if (next == NULL)
                return false;
            else
                curr = next;
        }
        return curr->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* curr = this;
        int len = prefix.size();
        for (int i = 0; i < len; i++) {
            int index = prefix[i] - 'a';
            Trie* next = curr->children[index];
            if (next == NULL)
                return false;
            else
                curr = next;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */