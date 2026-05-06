class Solution {
public:

    int firstPos(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1,indexFound=-1;

        while(low<=high){

            int mid = low + (high-low)/2;

            if(target > nums[mid]){
                low = mid+1;
            }
            else if(target < nums[mid]){
                high = mid-1;
            }
            else{
                indexFound=mid;
                high=mid-1;
            }
        }

        return indexFound;
    }

    int lastPos(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1,indexFound=-1;

        while(low<=high){

            int mid = low + (high-low)/2;

            if(target > nums[mid]){
                low = mid+1;
            }
            else if(target < nums[mid]){
                high = mid-1;
            }
            else{
                indexFound=mid;
                low=mid+1;
            }
        }

        return indexFound;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        

        int first = firstPos(nums,target);
        int last = lastPos(nums,target);

        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};