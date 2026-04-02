class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> m;
        int sum=0,count=0;
        m[0]=1;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int remainder=sum%k;
            if(remainder<0){
                remainder+=k;
            }

            if(m.find(remainder) != m.end()){
                count+= m[remainder];
                m[remainder]++;
            }
            else{
                m[remainder]=1;
            }
        }
        return count;
    }
};