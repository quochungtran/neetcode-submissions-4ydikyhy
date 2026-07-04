class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() : isWord(false) {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }

    void addWord(const string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }
};

class Solution {
    unordered_set<string> res;
    vector<vector<bool>> visited;
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            root->addWord(word);
        }
        
        int rows = board.size();
        int cols = board[0].size();
        visited.assign(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (root->children[board[r][c] - 'a'] != nullptr){
                    dfs(r, c, root, "", board);
                }
            }
        }
        return std::vector<string>(res.begin(), res.end());
    }

    void dfs(int r, 
                        int c,
                        TrieNode* node, 
                        string currWord,
                        const vector<vector<char>>& board)
    {
        int rows = board.size();
        int cols = board[0].size();
        
        char ch = board[r][c];
        node = node->children[ch - 'a'];
        currWord += ch;
        if (node->isWord){
            res.insert(currWord);
        }

        visited[r][c] = true;
        
        for (auto& dir: dirs){
            int nr = dir[0] + r;
            int nc = dir[1] + c;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc] 
                && node->children[board[nr][nc] - 'a'] != nullptr){
                dfs(nr, nc, node, currWord, board);
            }
        }

        visited[r][c] = false;
    }
};