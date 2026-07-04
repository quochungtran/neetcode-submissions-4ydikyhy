class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> mp(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n+1, 0);

        for (int j = n-1; j >= 0; j--){
            dp[j] = 1 + dp[j+1];
            for (int i = j; i < n; i++){
                if (mp.count(s.substr(j, i - j + 1))){
                    dp[j] = min(dp[j], dp[i+1]);
                }
            }
        }

        return dp[0];
    }

    int dfs(int i, const string& s, const unordered_set<string>& mp){
        if (i == s.size()){
            return 0;
        }
        int res = s.size();
        res = min(res, 1+dfs(i+1, s, mp));
        
        for (int j = i; j < s.size(); j++){
            if (mp.count(s.substr(i, j-i+1))){
                res = min(res, dfs(j+1, s, mp));
            }
        }
        
        return res;
    }
};
