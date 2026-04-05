class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.size() != endWord.size()){
            return 0;
        }

        return bfs(beginWord, endWord, wordList);
    }

    int bfs(string s1, string s2, vector<string>& wordList){
        queue<string> q;
        unordered_set<string> visited;

        q.push(s1);
        visited.insert(s1);
        int level = 0;

        while (!q.empty()){
            int currSize = q.size();
            level += 1;
            for (int i = 0; i < currSize; i++){
                auto curr = q.front();
                q.pop();

                if (curr == s2){
                    return level;
                }

                for (const auto& nextWord: getNextWord(curr, wordList)){
                    if (!visited.contains(nextWord)){
                        q.push(nextWord);
                        visited.insert(nextWord);
                    }
                }
            }
        }
        return 0;
    }

    vector<string> getNextWord(string w, vector<string>& wordList){
        vector<string> res;
        auto diff = [](string& w1, string& w2){
            if (w1.size() != w2.size()){
                return false;
            }
            int count = 0;
            for (int i = 0; i < w1.size(); i++){
                if (w1[i] != w2[i]){
                    count += 1;
                }
                if (count > 1){
                    return false;
                }
            }
            return count == 1;
        };

        for (auto word: wordList){
            if (diff(w, word) == 1){
                res.push_back(word);
            }
        }
        return res;
    }
};
