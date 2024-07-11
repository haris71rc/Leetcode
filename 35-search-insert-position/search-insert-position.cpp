class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<nums[0]) return 0;
        int start=0;
        int end=nums.size()-1;
        int mid= start + (end-start)/2;
        while(start<=end){
            if(target>nums[mid]){
                start=mid+1;
                cout<<"Start"<<start<<endl;
            }
            else if(target<nums[mid]){
                end=mid-1;
                cout<<"End"<<end<<endl;
            }
            else{
                return mid;
            }
            mid=start + (end-start)/2;
        }
        return end+1;
    }
};