class Solution {
public:
    vector<string> getNextLock(string lock) {
        vector<string> nexts;
        for (int i = 0; i < 4; ++i) {
            char original = lock[i];
            int c = original - '0';
            lock[i] = (c + 1) % 10 + '0';
            nexts.push_back(lock);
            lock[i] = (c + 9) % 10 + '0';            
            nexts.push_back(lock);
            lock[i] = original;
        }
        return nexts;
    }

    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }

        unordered_set<string> visit(deadends.begin(), deadends.end());
        if (visit.count("0000")) return -1;
        
        queue<string> q;
        q.push("0000");
        visit.insert("0000");
        int steps = 0;
        while (!q.empty()){
            auto sizeQ = q.size();
            for (int i = 0; i < sizeQ; i++){
                auto curr = q.front();
                q.pop();
                if (curr == target){
                    return steps;
                }
                for (const auto& nextLock: getNextLock(curr)){
                    if (visit.count(nextLock)){
                        continue;
                    }
                    visit.insert(nextLock);
                    q.push(nextLock);
                }
            }
            steps++;
        }

        return -1;
    }
};