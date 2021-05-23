/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Solution using extra memory vector of int and O(n) time complexity
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* h = head;
        if (h==NULL) 
            return true;
        vector<int>v;
        v.push_back(h->val);
        while(h->next != NULL){
            h = h->next;
            v.push_back(h->val);
        }
        int len = v.size();
        for (int i = 0, j = len-1 ; i<j ; i++, j--) {
            if(v[i] != v[j]){
                return false;
            }
        }
        return true;
    }
};


// Solution using extra memery stack of list node and O(n) time complexity
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* h = head;
        stack<ListNode*>s;
        if (h==NULL) 
            return true;
        s.push(h);
        while(h->next != NULL){
            h = h->next;
            s.push(h);
        }
        ListNode* now = head;
        while(!s.empty()){
            ListNode* v = s.top();
            s.pop();
            if(v->val != now->val){
                return false;
            }
            now = now->next;
        }
        return true;
    }
};
