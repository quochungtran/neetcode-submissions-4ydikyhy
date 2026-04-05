class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> adj(n, vector<int>());

        for (auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // init leaves as queue
        queue<int> leaves;
        unordered_map<int, int> count;

        auto computeFrom = [](queue<int>& leaves){
            vector<int> result;
            while (!leaves.empty())
            {
                auto l = leaves.front();
                leaves.pop();
                result.push_back(l);
            }
            return result;
        };
        for (int i = 0; i < n; i++){
            if (adj[i].size() == 1){
                leaves.push(i);
            }
            count[i] = adj[i].size();
        }
        while(!leaves.empty()){
            if (n <= 2){
                return computeFrom(leaves);
            }
            int numberCurrentLeaves = leaves.size();
            for (int i = 0; i < numberCurrentLeaves; i++){
                auto currLeave = leaves.front();
                leaves.pop();
                n -= 1;

                for (auto nei: adj[currLeave]){
                    count[nei] -= 1;
                    if (count[nei] == 1)
                        leaves.push(nei);
                }
            }
        }
        return vector<int>{};
    }
};