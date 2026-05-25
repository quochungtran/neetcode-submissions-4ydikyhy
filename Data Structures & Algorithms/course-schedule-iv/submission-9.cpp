class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reach (numCourses, vector<bool>(numCourses, false));
        for (auto preq: prerequisites){
            reach[preq[0]][preq[1]] = true;
        }

        for (int k = 0; k < numCourses; k++){
            for (int i = 0; i < numCourses; i++){
                for (int j = 0; j < numCourses; j++){
                    if (reach[i][k] && reach[k][j]){
                        reach[i][j] = true;
                    }
                }
            }
        }

        vector<bool> res;
        for (auto q: queries){
            res.push_back(reach[q[0]][q[1]]);
        }
        return res;
    }
};