class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start=0,end=nums.size()-1,pos=nums.size()-1;
        vector<int>ans(pos+1);
       

        while(start<=end){
            if(abs(nums[start])<abs(nums[end])){
                ans[pos] = nums[end]*nums[end];
                end--;
            }
            else{
                ans[pos] = nums[start]*nums[start];
                start++;
            }
            pos--;
        }
        return ans;
    }
};