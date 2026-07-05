struct TrieNode {
    TrieNode* children[26] = {nullptr};
    bool isWord = false;
    void addWord(string word) {
        TrieNode* curr = this;
        for (char c : word) {
            if (!curr->children[c - 'a']) curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }
};

struct pair_hash { inline size_t operator()(const pair<int, int> & v) const { return v.first * 31 + v.second; } };

class Solution {
    unordered_set<string> res;
    unordered_set<pair<int, int>, pair_hash> visited;
    int rows, cols;
    int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        rows = board.size();
        cols = board[0].size();

        for (auto& w: words){
            root->addWord(w);
        }

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (root->children[board[r][c] - 'a'] != nullptr){
                    dfs(r, c, "", board, root->children[board[r][c] - 'a']);
                }
            }
        }

        return vector<string>(res.begin(), res.end());
    }

    void dfs(int r, int c, string currWord, const vector<vector<char>>& board, TrieNode* node){
        currWord += board[r][c];
        if (node->isWord){
            res.insert(currWord);
        }

        visited.insert({r, c});
        for (auto& dir: dirs){
            int nr = dir[0] + r;
            int nc = dir[1] + c;

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited.count({nr, nc}) && node->children[board[nr][nc] - 'a']){
                dfs(nr, nc, currWord, board, node->children[board[nr][nc] - 'a']);
            }
        }
        visited.erase({r, c});
    }
};