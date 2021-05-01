class Solution {
public:
    int maxArea(vector<int>& height) {
    	int len = height.size();
    	int l = 0;
    	int r = len-1;
    	int ans = min(height[l], height[r]) * (r-l);
    	while(l<r){
    		if (height[l]<height[r]){
    			l++;
    		}
    		else{
    			r--;
    		}
    		ans = max(ans, min(height[l],height[r]) * (r-l));
    	}
    	return ans;     
    }
};
