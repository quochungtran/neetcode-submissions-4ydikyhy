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
            auto [isReach, result] = dfs(src, target, adj, visited);
            res.push_back(isReach ? result: -1.00); 
        }

        return res;
    }

private:
    pair<bool, double> dfs(const string& src, const string& target, unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& visited) {
        if (!adj.count(src) || !adj.count(target)) {
            return {false, -1.0};
        }
        if (src == target) {
            return {true, 1.0};
        }

        visited.insert(src);

        for (const auto& [nei, weight] : adj[src]) {
            if (!visited.count(nei)) {
                auto [isReach, result] = dfs(nei, target, adj, visited);
                if (isReach) {
                    return {true, weight * result};
                }
            }
        }

        return {false, -1.0};
    }
};