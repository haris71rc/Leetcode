class Solution {
private:
    bool doSplit(vector<int>& nums, int k, int x){
        int curr=0,currSplit=1;

        for(auto n: nums){
            if(n+curr > x){
                currSplit++;
                curr=n;
            }
            else{
                curr+=n;
            }
        }
        return currSplit<=k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        if(nums.size()<k) return -1;
        int low = INT_MIN,end=0,ans=0;

        for(auto s: nums){
            low = max(low,s);
            end+=s;
        }

        while(low<=end){
            int mid = low + (end-low)/2;

            if(doSplit(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};