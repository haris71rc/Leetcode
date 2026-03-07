class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int prod = nums[i];
            if(prod<k) ans++;
            int j = i+1;
            while(j<nums.size()){
                if(prod*nums[j]<k){
                    ans++;
                    prod=prod*nums[j];
                    // cout<<"i "<<nums[i]<<" prod "<<prod<<" nums[j] "<<nums[j]<<" ans "<<ans<<"\n";
                    j++;
                }
                else{
                    prod = 1;
                    break;
                }
            }

        }
        return ans;
    }
};