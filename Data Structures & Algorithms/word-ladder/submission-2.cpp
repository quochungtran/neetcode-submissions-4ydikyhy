class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
            return 0;
        }

        // build adj list: word -> list of patterns
        unordered_map<string, vector<string>> adj;
        wordList.push_back(beginWord);

        auto computePattern = [](const string& word, int pos){
            return word.substr(0, pos) + "*" + word.substr(pos+1);
        };

        for (const auto& word: wordList){
            for (int j = 0; j < word.size(); j++){
                auto pattern = computePattern(word, j);
                adj[pattern].push_back(word);
            }
        }

        unordered_set<string> visited{beginWord};
        queue<string> q;
        q.push(beginWord);
        int res=1;

        while (!q.empty()){
            int currSize = q.size();
            for (int i = 0; i < currSize; i++){
                auto word = q.front();
                q.pop();

                if (word == endWord){
                    return res;
                }

                for (int j = 0; j < word.size(); j++){
                    auto pattern = computePattern(word, j);
                    for (auto nei: adj[pattern]){
                        if (!visited.contains(nei)){
                            visited.insert(nei);
                            q.push(nei);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};
