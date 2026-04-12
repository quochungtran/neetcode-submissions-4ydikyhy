class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //

        auto pattern = [](const string& s){
            vector<string> res;
            for (int i = 0; i < s.size(); i++){
                auto p = s.substr(0, i) + "*" + s.substr(i+1);
                res.push_back(p);
            }
            return res;
        };
        
        unordered_map<string, vector<string>> adj;
        wordList.push_back(beginWord);
        for (auto w: wordList){
            for (auto p: pattern(w)){
                adj[p].push_back(w);
            }
        }

        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);
        int level = 0;
        while (!q.empty()){
            int q_size = q.size();
            level += 1;

            for (int i = 0; i < q_size; i++){

                auto curr = q.front();
                q.pop();
                if (curr == endWord){
                    return level;
                }
                for (auto p: pattern(curr)){
                    for (auto nei: adj[p]){
                        if (!visited.contains(nei)){
                            visited.insert(nei);
                            q.push(nei);
                        }
                    }
                }
            }            
        }
        return 0;
    }
};
