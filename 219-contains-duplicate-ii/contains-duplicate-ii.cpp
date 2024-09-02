class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                mp[nums[i]].push_back(i);
            }
            else{
                mp[nums[i]].push_back(i);
            }
        }
        bool ans=false;
        for(auto m:mp){
            if(m.second.size()>=2){
                for(int i=0;i<m.second.size()-1;i++){
                    if(abs(m.second[i]-m.second[i+1])<=k){
                        ans=true;
                    }
                }
            }
        }
        return ans;
    }
};