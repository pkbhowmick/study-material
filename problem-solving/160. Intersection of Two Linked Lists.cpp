/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// Solution: 
// Iterate over any link list and multiply all values with -1. 
// As the given values are positive, so when iterating over the second link list, 
// the first node with negative value is the intersection node.
// As the link lists structure can't be changed, so the negative values are returned back.  
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node = headA;
        while(node != NULL){
            node->val = node->val * (-1);
            node=node->next;
        }
        node = headB;
        ListNode *ans = NULL;
        while(node != NULL){
            if(node->val<0){
                ans=node;
                break;
            }
            node=node->next;
        }
        node = headA;
        while(node!=NULL){
            if(node->val>0)
                break;
            node->val=node->val*(-1);
            node=node->next;
        }
        return ans;
    }
};


