class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int pos=1;
        while(true){
            int flag = 1;
            for(int i=0;i<strs.size();i++){
                if(strs[i].size()<pos){
                    flag=0;
                    break;
                }
                else if(i+1<strs.size() && strs[i][pos-1]!=strs[i+1][pos-1]){
                    flag = 0;
                    break;
                }
            }
            if(flag==0)
                break;
            ans+=strs[0][pos-1];
            pos++;
        }
        return ans;
    }
};
