class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	vector<int>v[305];
    	for(int i=0;i<wordDict.size();i++){
    		string str = wordDict[i];
    		for(int j=0;j<s.size();j++){
    			int flag = 1;
    			int now=j;
    			for(int k=0;k<str.size();k++){
    				if (str[k]!=s[now]){
    			        flag = 0;
    					break;
    				}
    				now++;
    			}
    			if (flag){
    				v[j].push_back(j+str.size());

    			}

    		}
    	}
    	queue<int>q;
    	q.push(0);
    	int vis[305] = {0};
    	vis[0] = 1;
    	while(!q.empty()){
    		int u = q.front();
    		q.pop();
    		if(u==s.size()){
    			break;
    		}
    		for(int i=0;i<v[u].size();i++){
    			int vv = v[u][i];
    			if(vis[vv]==0){
    				q.push(vv);
    				vis[vv]=1;
    			}
    		}
    	}
    	if(vis[s.size()]==1){
    		return true;
    	}
    	else {
    		return false;
    	}
        
    }
};