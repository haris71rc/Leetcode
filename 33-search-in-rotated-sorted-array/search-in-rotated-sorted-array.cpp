class Solution {
private:
    
    int peak(vector<int>& nums, int n) {
    int start = 0;
    int end = n - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[end]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start; // 'start' will be the index of the smallest element (pivot)
}

    int solve(int start,int end,vector<int>& nums,int target){
        int s=start; 
        int e=end;  
        int mid=s + (e-s)/2;
        while(s<=e){
            if(target>nums[mid]){
                s=mid+1;
            }
            else if(target<nums[mid]){
                e=mid-1;
            }
            else{
                return mid;
            }
            mid=s +(e-s)/2;
        }
        return -1;
    }    
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=-1;
        int peakElement = peak(nums,n);
        cout<<peakElement<<endl;
        if(target>=nums[peakElement] && target<=nums[n-1]){
           ans=solve(peakElement,n-1,nums,target);
        }
        else{
            ans=solve(0,peakElement-1,nums,target);
        }
        return ans;
    }
};