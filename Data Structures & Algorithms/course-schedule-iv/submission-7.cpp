class Solution {
    unordered_map<int, vector<int>> adj;
    unordered_map<int, unordered_set<int>> preAdj;

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // build the adj list
        for (auto preq: prerequisites){
            auto crs1 = preq[0];
            auto crs2 = preq[1];
            adj[crs1].push_back(crs2);
        }

        // dfs for every single course to compute the pre-adjlist crs -> set of preq
        for (int crs = 0; crs < numCourses; crs++){
            buildPreqAdjList(crs);
        }

        // traversal each query and check the preq aspect 
        vector<bool> result;
        for (auto query: queries){
            if (preAdj[query[0]].contains(query[1])){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
        return result;
    }

    unordered_set<int> buildPreqAdjList(int crs){
        if (preAdj.find(crs) != preAdj.end()){
            return preAdj[crs];
        }
        unordered_set<int> preq = {};
        for (auto nei: adj[crs]){
            preq.insert(nei);
            auto listPreqOfNei = buildPreqAdjList(nei);
            preq.insert(listPreqOfNei.begin(), listPreqOfNei.end());
        }
        preAdj[crs] = preq;
        return preq;
    }
};