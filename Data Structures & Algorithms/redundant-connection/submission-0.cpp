class Solution {
    vector<vector<int>> adj;
    unordered_set<int> visited;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        adj = vector<vector<int>>(n, vector<int>());

        for (int i = 0; i < edges.size(); i++){
            auto edge = edges[i];
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
// O(V*(V+E))
            if (containsCycle(-1, a)){
                return edge;
            }
            visited.clear();
        }
        return {};
    }

    bool containsCycle(int prev, int a){
        if (visited.contains(a)){
            return true;
        }
        
        visited.insert(a);

        for (auto nei: adj[a]){
            if (nei == prev){
                continue;
            }
            if (containsCycle(a, nei)){
                return true;
            }
        }
        return false;
    }
};
