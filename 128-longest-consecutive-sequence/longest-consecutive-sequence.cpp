class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        map<int,int>mp;
        int count=1,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=nums[i]+1;
        }
        for(auto i: mp){
            if(mp.find(i.second) != mp.end()){
                //cout<<i.second<<endl;
                count++;
                maxi=max(count,maxi);
            }
            else{
                count = 1;
            }
        }
        return maxi == INT_MIN ? 1: maxi;
    }
};