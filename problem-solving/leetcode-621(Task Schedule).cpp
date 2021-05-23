class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    	int len = tasks.size();
    	if (n==0)
    		return len;
    	map<char,int>mp;
    	int mx = 0;
    	for(int i=0;i<tasks.size();i++){
    		mp[tasks[i]]++;
    		mx = max(mx,mp[tasks[i]]);
    	}
    	int ans = max(len,mx*n);
    	return ans;
    }
};