class Solution {
    int rows; 
    int cols;
    int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
public:
    void dfs(int r, int c,vector<vector<char>>& board){
        board[r][c] = '#';

        for (auto d: dirs){
            auto dr = d[0], dc = d[1];
            auto nr = dr + r, nc = dc + c;
            if (nr >= 0 && nc >= 0 && nr <= rows-1 && nc <= cols-1 && board[nr][nc] == 'O'){
                dfs(nr, nc, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        // find all cells from edges containing 'O' char
        // do dfs from each cell to find all 
        // group 'O' from board, marking as '#' char
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (r == 0 || r == rows-1 || c == 0 || c == cols-1){
                    if (board[r][c] == 'O'){
                        dfs(r, c, board);
                    }
                }
            }
        }
        // iterate again board, if each cell marking #, turn it to O
        // if each cell mark O turn to X since they are connected and surround by 'X'
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
                if (board[r][c] == '#'){
                    board[r][c] = 'O';
                }
            }    
        }
    }
};
