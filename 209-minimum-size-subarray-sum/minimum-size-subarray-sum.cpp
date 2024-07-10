class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,count=INT_MAX,sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                count=min(count,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return count==INT_MAX ? 0:count;
    }
};