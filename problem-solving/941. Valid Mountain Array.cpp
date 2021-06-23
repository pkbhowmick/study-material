class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        int st=0;
        while(st+1<arr.size()){
            if(arr[st]<arr[st+1])
                st++;
            else
                break;
        }
        int ed=arr.size()-1;
        while(ed-1>=0){
            if(arr[ed]<arr[ed-1])
                ed--;
            else
                break;
        }
        if(st==ed && st>0 && ed<arr.size()-1)
            return true;
        return false;
    }
};

