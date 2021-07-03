// Solution-1: Using DP
// Not the best solution,
// Leetcode runtime: 1676 ms
// Leetcode memory: 48.7 MB

class Solution {
public:
    int dp[1001][1001][3][3];
    int solve(vector<int>& rating,int pos, int prev, int count, int flag){
        if(count == 3){
            return 1;
        }
        if (pos>=rating.size()){
            return 0;
        }
        if(dp[pos][prev][count][flag]!=-1)
            return dp[pos][prev][count][flag];

        int ans = 0;
        if(flag == 0){
            if(rating[pos]>rating[prev])
                ans += solve(rating, pos+1, pos, count+1, 2);
            if(rating[pos]<rating[prev])
                ans += solve(rating, pos+1, pos, count+1, 1);
            ans += solve(rating, pos+1, prev, count, flag);
        }
        else if(flag == 1){
            if(rating[pos]<rating[prev])
                ans += solve(rating, pos+1, pos, count+1, 1);
            ans += solve(rating, pos+1, prev, count, flag);
        }
        else if(flag == 2){
            if(rating[pos]>rating[prev])
                ans += solve(rating, pos+1, pos, count+1, 2);
            ans += solve(rating, pos+1, prev, count, flag);
        }

        return dp[pos][prev][count][flag] = ans;
    }
    int numTeams(vector<int>& rating) {
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for(int i=0;i<rating.size();i++){
            ans += solve(rating, i+1, i, 1, 0);
        }
        return ans;
    }
};


// Solution-2: 
// Brute force n^2 solution with better runtime 
// and memory than above dp solution
// Leetcode runtime: 192 ms and memory: 8.8 MB

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int len = rating.size();
        int ans = 0;
        for(int i=0;i<len;i++){
            int less1 = 0;
            int gret1 = 0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i])
                    less1++;
                if(rating[j]>rating[i])
                    gret1++;
            }
            int less2=0;
            int gret2=0;
            for(int j=i+1;j<len;j++){
                if(rating[j]<rating[i])
                    less2++;
                if(rating[j]>rating[i])
                    gret2++;
            }
            ans += less1*gret2 + less2*gret1;
        }
        return ans;
    }
};