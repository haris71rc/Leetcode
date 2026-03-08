class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> uniqueAns;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int k=j+1,l=nums.size()-1;
                while(k<l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum<target){
                        k++;
                    }
                    else if(sum>target){
                        l--;
                    }
                    else{
                        uniqueAns.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                }
            }
        }
        for(auto i: uniqueAns){
            ans.push_back(i);
        }
        return ans;
    }
};