class Solution {
    unordered_map<int, vector<int>> adj;
    unordered_set<int> cycle;
    int cycleStart = -1;
    unordered_set<int> visited;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        for (auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        findCycle(1, -1);

        for (auto i = edges.size() - 1; i >= 0; i--){
            int e1 = edges[i][0], e2 = edges[i][1];
            if (cycle.contains(e1) && cycle.contains(e2)){
                return edges[i];
            }
        }
        return {};
    }

    bool findCycle(int src, int prev){
        if (visited.contains(src)){
            cycleStart = src;
            return true;
        }
        visited.insert(src);
        for (auto nei: adj[src]){
            if (nei == prev){
                continue;
            }
            if (findCycle(nei, src)){
                if (cycleStart != -1){
                    cycle.insert(nei);
                }
                if (cycleStart == src){
                    cycleStart = -1;
                }
                return true;
            }
        }
        return false;
    }
};
