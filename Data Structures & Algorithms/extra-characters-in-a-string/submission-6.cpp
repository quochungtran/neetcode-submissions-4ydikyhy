class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
        isWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void addWord(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;
        for (const string& word: dictionary){
            trie.addWord(word);
        }
        int n = s.size();
        vector<int> dp(n+1);

        for (int i = n - 1; i >= 0; i--){
            dp[i] = dp[i+1] + 1;
            TrieNode* curr = trie.root;

            for (int j = i; j < n; j++){
                if (!curr->children[s[j]-'a']) break;
                curr = curr->children[s[j]-'a'];
                if (curr->isWord){
                    dp[i] = min(dp[i], dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};