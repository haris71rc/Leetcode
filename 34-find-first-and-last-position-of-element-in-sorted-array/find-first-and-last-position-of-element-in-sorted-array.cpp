class Solution {
private:
    int firstPos(vector<int>& nums, int target,int n){
        int start=0;
        int end=n-1;
        int mid = start + (end-start)/2;
        int sol=-1;
        while(start<=end){           
            if(target<nums[mid]){
                end=mid-1;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }
            else{
                sol=mid;
                end=mid-1;
            }
            mid = start + (end-start)/2;
        }
        return sol;
    }   
    int lastPos(vector<int>& nums, int target,int n){
        int start=0;
        int end=n-1;
        int mid = start + (end-start)/2;
        int sol=-1;
        while(start<=end){           
            if(target<nums[mid]){
                end=mid-1;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }
            else{
                sol=mid;
                start=mid+1;
            }
            mid = start + (end-start)/2;
        }
        return sol;
    }   
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        int first = firstPos(nums,target,n);
        int last = lastPos(nums,target,n);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};