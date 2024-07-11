class Solution {
private:
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
    int findPeakElement1(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
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
public:
    int findMin(vector<int>& nums) {
        int peakElement = findPeakElement1(nums);
        cout<<peakElement;
        return nums[peakElement];
    }
};