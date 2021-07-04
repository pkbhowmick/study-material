// Solution - 1: 
// Recursion

class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        return fib(n-1)+fib(n-2);
    }
};



// Solution - 2:
// Recursive dp
class Solution {
public:
    int dp[35];
    int fib(int n) {
        if(n<=1) return n;
        if(dp[n]!=0) return dp[n];
        return dp[n] = fib(n-1)+fib(n-2);
    }
};



// Solution - 3:
// Iterative DP
class Solution {
public:
    int f[35];
    int fib(int n) {
        f[0] = 0;
        f[1] = 1;
        for(int i=2;i<=n;i++){
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
};
