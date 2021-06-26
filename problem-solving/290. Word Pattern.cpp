class Solution {
public:
    vector<string> getWords(string str){
        string word;
        stringstream iss(str);
        vector<string>words;
        while(iss>>word){
            words.push_back(word);
        }
        return words;
    }
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        words = getWords(s);
        int len = words.size();
        if(pattern.size()!=words.size()){
            return false;
        }
        map<char,string>mp;
        map<string,int>av;
        for(int i=0;i<len;i++){
            if(mp.find(pattern[i])==mp.end()){
                if(av.find(words[i])!=av.end()){
                    return false;
                }
                mp[pattern[i]] = words[i];
                av[words[i]]=1;
            }
            else if(mp[pattern[i]]!=words[i]){
                return false;
            }
        }
        return true;
    }
};
