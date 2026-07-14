class Solution {
    unordered_set<string> visit;
    unordered_map<string, vector<pair<string, double>>> adj;

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        // build relations Graph 
        // hashmap:  key: src, b: list of {des, ratio}
        adj.clear();
        for (int i = 0; i < equations.size(); i++){
            auto equation = equations[i];
            auto value = values[i];
            adj[equation[0]].push_back({equation[1], value});
            adj[equation[1]].push_back({equation[0], 1.0/value});
        }

        // compute the answer for each queries
        unordered_map<string, unordered_map<string, double>> preCompute;

        vector<double> result;
        for (auto query: queries){
            visit.clear();
            if (adj.count(query[0]) && adj.count(query[1]) && dfs(query[0], query[1], preCompute, 1.0)){
                result.push_back(preCompute[query[0]][query[1]]);
            }
            else{
                result.push_back(-1.0);
            }
        }
        return result;
    }
    bool dfs(string src, string des, unordered_map<string, unordered_map<string, double>>& preCompute, double currentVal){
        if (src == des){
            preCompute[src][des] = currentVal;
            return true;
        }
        visit.insert(src);

        for (auto [nei, ratio]: adj[src]){
            if (!visit.contains(nei))
            {
                if (dfs(nei, des, preCompute, currentVal * ratio)){
                    preCompute[src][des] = preCompute[nei][des];
                    return true;
                }
            }
        }

        return false;
    }
};