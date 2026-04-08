class Solution {
    unordered_map<string, vector<pair<string, double>>> adj;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int n = equations.size();

        for (int i = 0; i < n; i++){
            auto equation = equations[i];
            auto value = values[i];
            adj[equation[0]].push_back({equation[1], value});
            adj[equation[1]].push_back({equation[0], 1.0/value});
        }
        vector<double> res;
        for (auto query: queries){
            auto q1 = query[0], q2 = query[1];
            res.push_back(bfs(q1, q2));
        }

        return res;
    }

    double bfs(string src, string des){
        if (adj.count(src) == 0 || adj.count(des) == 0){
            return -1.0;
        }
        unordered_set<string> visited{src};
        queue<pair<string, double>> q;
        q.push({src, 1.0});
        
        while (!q.empty()){
            auto [curr, curr_w] = q.front();
            q.pop();

            if (curr == des){
                return curr_w;
            }
            for (auto [nei, nei_w]: adj[curr]){
                if (!visited.contains(nei)){
                    visited.insert(nei);
                    q.push({nei, curr_w * nei_w});
                }
            }
        }

        return -1.0;
    }
};
