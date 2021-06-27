class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        int len=nums.size();
        int i = 0;
        int j = len-1;
        while(i<=j){
            if(nums[i]<0){
                nums[i] *= -1;
            }
            if(nums[j]<0){
                nums[j]*= -1;
            }
            if(nums[i]>nums[j]){
                ans.push_back(nums[i]*nums[i]);
                i++;
            }
            else{
                ans.push_back(nums[j]*nums[j]);
                j--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};