// Solution-1:
// Very easy and short solution just sort the array
// and return the kth largest element from the array.
// 
// Time Complexity: O(n log n) where n is the array size
// Space Complexity: O(1) i.e. using no extra spaces
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int idx = nums.size() - k;
        return nums[idx];
    }
};

// Solution-2:
// As the values of the array bounded from -10^4 to 10^4,
// so the values can be marked as array index. Then the values
// can be counted from reverse and then kth largest element 
// can be calculated easily.
// 
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: Here we need extra space.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int arr[20001];
        int mx = 10000;  
        memset(arr, 0, sizeof arr);
        for(int i=0;i<nums.size();i++){
            arr[nums[i]+mx]++;
        }
        int tot = 0;
        int ans;
        for(int i=20000;i>=0;i--){
            tot+=arr[i];
            if(tot>=k){
                ans = i-mx;
                break;
            }
        }
        return ans;
    }
};

// Solution-3:
// Using priority queue(min heap)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            if(pq.empty() || nums[i]>pq.top() || pq.size() < k){
                pq.push(nums[i]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
            
        }
        return pq.top();
    }
};
