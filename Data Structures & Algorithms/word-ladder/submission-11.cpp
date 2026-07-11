class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        int res = 1;
        unordered_set<string> visit;
        visit.insert(beginWord);
        queue<string> q;
        q.push(beginWord);

        unordered_map<string, vector<string>> patterns;
        wordList.push_back(beginWord);
        
        auto makePattern = [&](const string& st){
            vector<string> res;
            for (int i = 0; i < st.size(); i++){
                auto newPattern = st.substr(0, i) + '*' + st.substr(i+1);
                res.push_back(newPattern);
            }
            return res;
        };

        for (auto w: wordList){
            for (const auto& p: makePattern(w)){
                patterns[p].push_back(w);
            }
        }


        while(!q.empty()){
            auto qSize = q.size();
            for (int i = 0; i < qSize; i++)
            { 
                auto curr = q.front();
                q.pop();
                if (curr == endWord){
                    return res;
                }

                for (auto p: makePattern(curr))
                { 
                    for (const auto& nextWord: patterns[p])
                    {
                        if (!visit.count(nextWord)){
                            visit.insert(nextWord);
                            q.push(nextWord);
                        }
                    }
                }
            }
            res++;
 
        }
        return 0;
    }
};