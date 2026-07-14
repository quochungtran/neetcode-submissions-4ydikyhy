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
            res.push_back(dfs(src, target, adj, unordered_set<string>()));
        }

        return res;
    }

private:
    double dfs(const string& src, const string& target, unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string> visited) {
        if (!adj.count(src) || !adj.count(target)) {
            return -1.0;
        }
        if (src == target) {
            return 1.0;
        }

        visited.insert(src);

        for (const auto& [nei, weight] : adj[src]) {
            if (!visited.count(nei)) {
                double result = dfs(nei, target, adj, visited);
                if (result != -1.0) {
                    return weight * result;
                }
            }
        }

        return -1.0;
    }
};