// Solution-1:
// Using recursive dp
// Time complexity: O(coins * amount)

class Solution {
public:
    int dp[13][10001];
    int INF = 10000000;
    int call(vector<int>& coins, int pos, int amount){
        if(pos==coins.size()){
            if(amount==0)
                return 0;
            return INF;
        }
        if (amount < 0)
            return INF;
        if(dp[pos][amount]!=-1)
            return dp[pos][amount];
        
        int ret1 = 1 + call(coins, pos, amount-coins[pos]);
        int ret2 = call(coins, pos+1, amount);
        return dp[pos][amount] = min(ret1,ret2);

    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof dp);
        int ans = call(coins, 0, amount);
        if(ans==INF)
            ans = -1;
        return ans;
    }
};
