class TrieNode {
public:
    std::array<std::unique_ptr<TrieNode>, 26> children{};
    bool isWord = false;

    void addWord(std::string_view word) {
        TrieNode* cur = this;
        for (char c : word) {
            auto& slot = cur->children[c - 'a'];
            if (!slot) {
                slot = std::make_unique<TrieNode>();
            }
            cur = slot.get();
        }
        cur->isWord = true;
    }
};

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board,
                                        std::vector<std::string>& words) {
        auto root = std::make_unique<TrieNode>();
        for (const auto& word : words) {
            root->addWord(word);
        }

        rows_ = static_cast<int>(board.size());
        cols_ = static_cast<int>(board[0].size());
        visited_.assign(rows_, std::vector<bool>(cols_, false));
        board_ = &board;

        std::string path;
        path.reserve(16);

        for (int r = 0; r < rows_; ++r) {
            for (int c = 0; c < cols_; ++c) {
                char ch = board[r][c];
                if (root->children[ch - 'a']) {
                    dfs(r, c, root.get(), path);
                }
            }
        }
        return {result_.begin(), result_.end()};
    }

private:
    std::unordered_set<std::string> result_;
    std::vector<std::vector<bool>> visited_;
    std::vector<std::vector<char>>* board_ = nullptr;
    int rows_ = 0;
    int cols_ = 0;

    static constexpr std::array<std::array<int, 2>, 4> kDirs{{
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    }};

    void dfs(int r, int c, TrieNode* node, std::string& path) {
        char ch = (*board_)[r][c];
        node = node->children[ch - 'a'].get();

        path.push_back(ch);
        if (node->isWord) {
            result_.insert(path);   // still copies into the set, but no per-call string copy during recursion
        }

        visited_[r][c] = true;

        for (auto [dr, dc] : kDirs) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr >= 0 && nr < rows_ && nc >= 0 && nc < cols_ &&
                !visited_[nr][nc] && node->children[(*board_)[nr][nc] - 'a']) {
                dfs(nr, nc, node, path);
            }
        }

        visited_[r][c] = false;
        path.pop_back();
    }
};