class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj; // Map a -> list of [b, a/b]

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            adj[a].emplace_back(b, values[i]);
            adj[b].emplace_back(a, 1.0 / values[i]);
        }

        vector<double> res;
        for (const auto& query : queries) {
            string src = query[0];
            string target = query[1];
            unordered_set<string> visited;
            res.push_back(bfs(src, target, adj, visited));
        }

        return res;
    }

private:
    double bfs(const string& src, const string& target, unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& visit) {
        if (!adj.count(src) || !adj.count(target)){
            return -1;
        }
        
        queue<pair<string, double>> q;
        q.push({src, 1.0});
        visit.insert(src);
        while (!q.empty()){
            auto [curr, result] = q.front();
            q.pop();

            if (curr == target){
                return result;
            }

            for (auto [nei, weight]: adj[curr]){
                if (!visit.contains(nei)){
                    visit.insert(nei);
                    q.push({nei, result * weight});
                }
            }
        }

        return -1;
        
    }
};