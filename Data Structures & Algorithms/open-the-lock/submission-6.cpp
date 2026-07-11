class Solution {
public:
    vector<string> getNextLock(string lock) {
        vector<string> nexts;
        for (int i = 0; i < 4; ++i) {
            char c = lock[i];
            lock[i] = (c == '9' ? '0' : c + 1);
            nexts.push_back(lock);
            lock[i] = (c == '0' ? '9' : c - 1);
            nexts.push_back(lock);
            lock[i] = c;
        }
        return nexts;
    }

    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }

        unordered_set<string> visit(deadends.begin(), deadends.end());
        if (visit.count("0000")) return -1;

        unordered_set<string> begin{"0000"}, end{target};

        int steps = 0;

        while (!begin.empty() && !end.empty()){
            steps++;
            // always expand the smallest frontier
            if (begin.size() > end.size()) 
            swap(begin, end);

            unordered_set<string> next;
            for (const auto& lock: begin){
                for (auto nextLock: getNextLock(lock)){
                    if (end.count(nextLock)) return steps;
                    if (!visit.count(nextLock)) {
                        visit.insert(nextLock);
                        next.insert(nextLock);
                    }                        
                }
            }
            begin = next;
        }
        return -1;
    }
};