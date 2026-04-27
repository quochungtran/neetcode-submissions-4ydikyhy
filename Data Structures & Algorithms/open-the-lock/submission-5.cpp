class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // BFS running from 0000 state to target 
        // we turn or deadends 0000, target to nodes of a graph
        // when we reach to target we return the minimum steps

        unordered_set<string> deadEnds_set(deadends.begin(), deadends.end());
        if (deadEnds_set.contains("0000")) return -1;

        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;  
        visited.insert("0000");


        int times = 0;

        while(!q.empty()){            
            const auto qSize = q.size();
            for (int i = 0; i < qSize; i++){
                auto curr = q.front();
                q.pop();

                if (curr == target)
                    return times;

                if (deadEnds_set.contains(curr)){
                    continue;
                }
                
                for (auto nextState: getNextState(curr)){
                    if (!visited.contains(nextState)){
                        visited.insert(nextState);
                        q.push(nextState);
                    }
                }
            }
            times++;
        }

        return -1;
    }

    vector<string> getNextState(const string& curr){
        vector<string> res;
        res.reserve(8);
        
        for (int i = 0; i < 4; i++){
            const int digit = curr[i] - '0';

            auto nextStage = [&](int delta){
                string next = curr;
                next[i] = '0' + (digit + delta + 10)%10;
                return next; 
            };

            res.push_back(nextStage(1));
            res.push_back(nextStage(-1));
        }

        return res;
    }
};