class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};


class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }

    void addWord(string word){
        TrieNode* cur = root;
        for(auto c: word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr){
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }

    bool findWord(string word){
        TrieNode* cur = root;
        for (char c: word){
            int i = c - 'a';
            if (cur->children[i] == nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return cur->endOfWord;
    }
};
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        PrefixTree trie;
        for (auto& word: dictionary){
            trie.addWord(word);
        }

        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + 1;
            for (int j = i; j < n; j++) {
                if (trie.findWord(s.substr(i, j - i + 1))) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};