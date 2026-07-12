class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++){
            for (auto coin: coins){
                if (i - coin >= 0){
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }

        return dp[amount] == 1e9 ? -1: dp[amount];
    }

    int dfs(vector<int>& coins, int amount)
    {
        if (amount == 0){
            return 0;
        }
        int res = 1e9;
        for (const auto& coin: coins){
            if (amount - coin >= 0){
                res = min(res, 1+ dfs(coins, amount - coin));
            }
        }
        
        return res;
    }
};
