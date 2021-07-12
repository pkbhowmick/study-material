// Solution-1: 
// Using two pointer technique
// Time complexity: O(size of s * size of t) i.e. O(n)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos = 0;
        for(int i=0;i<t.size() && pos<s.size();i++){
            if(s[pos]==t[i]){
                pos++;
            }
        }
        if(pos == s.size())
            return true;
        return false;
    }
};

// Solution-2(follow up):
// Using binary search technique
// Time complexity: O(nlogn)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<int>vec[26];
        for(int i=0;i<t.size();i++){
            int now = t[i] - 'a';
            vec[now].push_back(i);
        }

        int cur = -1;

        for(int i=0;i<s.size();i++){
            int now = s[i] - 'a';
            auto it = upper_bound(vec[now].begin(),vec[now].end(),cur);
            if(it == vec[now].end())
                return false;
            cur = *it;
        }
        return true;
    }
};