class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // 1 1 0
        // 0 1 1
        // 0 1 2
        // queue : storing current rotting fruit for each level of traversal
        // visit indicator: changing grid in place with the already visited rotting fruit to avoid revist rotting fruit.
        // 2 -> 0. 
        // minimumMins, numberRotting < refreshFruit at the end return -1

        queue<pair<int, int>> q;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        // push every rotting fruit at the beginning, first traversal
        int m = grid.size();
        int n = grid[0].size();
        int refreshFruit = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2){
                    q.push({i, j});
                }
                if (grid[i][j] == 1){
                    refreshFruit++;
                }
            }
        }
        // bfs
        int numberRotting = 0;
        int minimumMins = 0;
        while (!q.empty()){
            int currSize = q.size();
            for (int i = 0; i < currSize; i++){
                auto [r ,c] = q.front();
                grid[r][c] = 0;
                q.pop();
                for (const auto& dir: dirs){
                    auto nr = r + dir[0];
                    auto nc = c + dir[1];
                    auto validEmpty = [&](int r, int c){
                        return (r >= 0 && r <= m-1 && c >= 0 && c <= n-1);
                    };
                    if (validEmpty(nr, nc) && grid[nr][nc] == 1){
                        q.push({nr, nc});
                        grid[nr][nc] = 2;
                        numberRotting++;
                    }
                }
            }
            if (!q.empty())
                minimumMins++;
        }
        return numberRotting < refreshFruit ? -1 : minimumMins;
    }
};
