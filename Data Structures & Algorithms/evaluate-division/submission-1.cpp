class Solution {
    unordered_map<string, vector<pair<string, double>>> adj;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // build adj list
        int n = equations.size();
        for (int i = 0; i < n; i++){
            string firstStr = equations[i][0];
            string secondStr = equations[i][1];
            auto weight = values[i];
            adj[firstStr].push_back({secondStr, weight});
            adj[secondStr].push_back({firstStr, 1.0/weight});
        }
        vector<double> res;
        for (auto querie: queries){
            auto src = querie[0];
            auto des = querie[1];
            res.push_back(bfs(src, des));
        }   

        return res;
    }
    double bfs(string src, string des){
        if (!adj.contains(src) || !adj.contains(des)){
            return -1.0;
        }

        unordered_set<string> visited;
        queue<pair<string, double>> q;

        q.push({src, 1.0});
        visited.insert(src);

        while(!q.empty()){
            auto [curr, curr_wei] = q.front();
            q.pop();

            if (curr == des){
                return curr_wei;
            }
            for (auto [nei, w]: adj[curr]){
                if (!visited.contains(nei))
                {
                    q.push({nei, curr_wei * w});
                    visited.insert(nei);
                }
            }
        }
        return -1.0;
    }
};