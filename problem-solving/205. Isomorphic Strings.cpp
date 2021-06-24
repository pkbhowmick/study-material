class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp,av;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i])
                    return false;
            }
            else if(av.find(t[i])!=av.end())
                return false;
            else{
                mp[s[i]]=t[i];
                av[t[i]]=s[i];
            }
        }
        return true;
    }
};
