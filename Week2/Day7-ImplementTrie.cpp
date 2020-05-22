class Trie {
public:
    /** Initialize your data structure here. */
    Trie* children[26];
    bool endOfWord;

    Trie() {
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        endOfWord=false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr = this;
        int n = word.size();
        for(int i=0;i<n;i++){
            int c = word[i]-'a';
            if((curr->children)[c]==NULL){
                (curr->children)[c] = new Trie();
            }
            curr = (curr->children)[c];
        }
        curr->endOfWord=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* curr = this;
        int n = word.size();
        for(int i=0;i<n;i++){
            int c = word[i]-'a';
            if((curr->children)[c] == NULL)
                return false;
            curr = (curr->children)[c];
        }
        return curr->endOfWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size();
        Trie* curr = this;
        for(int i=0;i<n;i++){
            int c = prefix[i]-'a';
            if((curr->children)[c]==NULL)
                return false;
            curr = (curr->children)[c];
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
