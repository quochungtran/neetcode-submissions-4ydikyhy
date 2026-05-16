class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // patterns to Words
        unordered_map<string, vector<string>> patternToWords;
        auto patterns = [](const string& str){
            vector<string> patternList;
            for (int i = 0; i < str.size(); i++){
                auto s = str.substr(0, i) + '*' + str.substr(i+1);
                patternList.push_back(s);
            }
            return patternList;
        };

        wordList.push_back(beginWord);
        for (auto w: wordList){
            for (auto p: patterns(w)){
                patternToWords[p].push_back(w);
            }
        }

        // bfs
        queue<string> q;
        unordered_set<string> visit;
        q.push(beginWord);
        visit.insert(beginWord);
        int result = 1;
        while (!q.empty()){

            auto currSize = q.size();
            for (int i = 0; i < currSize; i++){
                auto curr = q.front();
                q.pop();
                if (curr == endWord){
                    return result;
                }

                for (auto pattern: patterns(curr)){
                    for (auto word: patternToWords[pattern]){
                        if (!visit.contains(word)){
                            q.push(word);
                            visit.insert(word);
                        }
                    }
                }
            }
                result++;

        }

        return 0;
    }
};
