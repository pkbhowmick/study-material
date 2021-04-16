
// Description: Given an array nums of n integers where nums[i] is in the range [1, n], 
// return an array of all the integers in the range [1, n] that do not appear in nums.

// Time complexity: O(n)
// Space complexity: O(n) 

// Without using any extra space

// Solution Idea: Iterate over all elements and add an arbitary valur greater than array length on the element index
// to keep track the appead integers. 




class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]>len){
                int id = nums[i]-len;
                if (nums[id-1]<=len)
                    nums[id-1]+=len;
            }
            else{
                if(nums[nums[i]-1]<=len)
                    nums[nums[i]-1]+=len;
            }
        }
        vector<int>ans;
        for(int i=0;i<len;i++){
            if(nums[i]<=len)
                ans.push_back(i+1);
            
        }
        return ans;
    }
};

