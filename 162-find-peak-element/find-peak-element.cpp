class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        int mid=start + (end-start)/2;
        while(start<end){
            if(nums[mid]>nums[mid+1]){
                end=mid;                
            }
            else{
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return start;
    }
};