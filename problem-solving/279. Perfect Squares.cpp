// Solution-1:
// This problem can be solved using dynamic programming.
// Time Complexity: O(n)

class Solution {
public:
    int dp[10004];
    int solve(int n){
        if(n<=3) return n;
        if(dp[n]!=-1) return dp[n];
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solve(n-i*i));
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof dp);
        return solve(n);
    }
};