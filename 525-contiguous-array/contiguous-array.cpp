class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        int prefix=0,maxLen=0;
        m[0]=-1;

        for(int i=0;i<n;i++){
            if(nums[i] == 0) prefix-=1;
            else prefix+=1;

            if(m.find(prefix) != m.end()){
                maxLen=max(maxLen,i-m[prefix]);
            }
            else{
                m[prefix]=i;
            }
        }

        return maxLen;
    }
};