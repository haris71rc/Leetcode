class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bucket1=0,bucket2=0;
        long res=0;
        for(int i=0;i<nums.size();i++){
            res=res^nums[i];
        }
         int x=(res&(res-1))^res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&x){
                bucket1^=nums[i];
            }
            else{
                bucket2^=nums[i];
            }
        }
        return {bucket1,bucket2};
    }
};