// Solution:
// This problem can be solved using slow pointer and fast pointer concept.
// Time Complexity: O(n)
// Space Complexity: O(1) i.e. using no extra space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
