class Solution {
private:
    vector<vector<bool>> reach;
    unordered_map<int, vector<int>> adj;

    void bfs(int crs, int numberCourses){
        queue<int> q;
        q.push(crs);

        reach[crs][crs] = true;

        while(!q.empty()){
            auto curr = q.front(); q.pop();

            for (auto nei: adj[curr]){
                if (!reach[crs][nei]){
                    reach[crs][nei] = true;
                    q.push(nei);
                }
            }
        }
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // init steps
        for (const auto& preq: prerequisites){
            adj[preq[0]].push_back(preq[1]);
        }
        reach = vector<vector<bool>>(numCourses, vector<bool>(numCourses, false));

        // building precomputed transitive closure reach[i][j] indicate that 
        for (int i = 0; i < numCourses; i++){
            bfs(i, numCourses);
        }

        // interface
        vector<bool> res;
        for (const auto& query: queries)
            res.push_back(reach[query[0]][query[1]]);
        return res;
    }
};