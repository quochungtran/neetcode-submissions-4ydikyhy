class Solution {
public:
    int romanToInt(string s) {
        // hashmap sympol -> value int
        unordered_map<string, int> symPolToInterger = {
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000},
            {"IV", 4},
            {"IX", 9},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900}
        };
        // interation of s
        int index = 0;
        int res = 0;
        while (index < s.size()){
            if (index + 1 < s.size() && symPolToInterger.contains(s.substr(index, 2))){
                res = res + symPolToInterger[s.substr(index, 2)];
                index = index + 2;
            }
            else{
                string curr = std::string("")  + s[index];
                res = res + symPolToInterger[curr];
                index++;
            }
        }
        return res;
    }
};