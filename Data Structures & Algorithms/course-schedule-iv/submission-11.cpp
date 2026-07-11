class Solution {
    unordered_map<int, unordered_set<int>> preCompute;
    vector<int> visit;
    vector<vector<int>> adj;
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adj.assign(numCourses, {});
        visit.assign(numCourses, false);
        vector<bool> res;

        for (auto& preq: prerequisites){
            adj[preq[0]].push_back(preq[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            dfs(i);
        }

        for (auto q: queries){
            res.push_back(preCompute[q[0]].count(q[1]));
        }
        return res;
    }

    unordered_set<int> dfs(int src){
        if (visit[src]) 
            return preCompute[src];
        unordered_set<int> res;
        visit[src] = true;

        for (auto nei: adj[src]){
            res.insert(nei);
            auto a = dfs(nei);
            res.insert(a.begin(), a.end());
        }
        preCompute[src] = res;
        return res;
    }
};