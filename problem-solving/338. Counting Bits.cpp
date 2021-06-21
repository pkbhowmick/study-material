// Solution-1:
// Dividing all integers from 1 to n by 2 and count the on bits.
// Time Complexity: O(n log n)

class Solution {
public:
    int getNumberOfOnes(int x){
        int cnt=0;
        while(x!=0){
            if(x%2)
                cnt++;
            x/=2;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(getNumberOfOnes(i));
        }
        return ans;      
    }
};


// Solution-2:
// Using dynamic programming the problem can be solved in linear time.
// Time Complexity: O(n)
//
// Explanation: When a number (say n) is even, then it's number of on bit will be equal to n/2. 
// Like 14 (1110) has no extra on bit than 7 (111)
// But when n is odd, then one extra on bit than (n/2) is added.
// 11 (1011) has one extra on bit than 5 (101).
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(i%2)
                dp[i] = dp[i/2]+1;
            else
                dp[i] = dp[i/2];
        } 
        return dp;     
    }
};

