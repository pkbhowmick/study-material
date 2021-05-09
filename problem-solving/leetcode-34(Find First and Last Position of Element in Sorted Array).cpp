// Solution Idea: Just run two binary search to get the indexes.
// One binary search for the left index and another one for the right index. 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans1=-1;
        int lo=0;
        int hi=nums.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]==target){
                ans1=mid;
                hi=mid-1;
            }
            else if(nums[mid]>target)
                hi = mid -1;
            else 
                lo = mid +1;
        }
        int ans2=-1;
        lo=0;
        hi=nums.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]==target){
                ans2=mid;
                lo=mid+1;
            }
            else if(nums[mid]>target)
                hi = mid -1;
            else 
                lo = mid +1;
        }
        vector<int>ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};