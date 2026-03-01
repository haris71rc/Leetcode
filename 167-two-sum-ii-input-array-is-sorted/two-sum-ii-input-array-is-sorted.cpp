class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int start=0,end=numbers.size()-1;
        while(start<end){
            int sum = numbers[start] + numbers[end];
            if(sum==target) {
                ans = {start+1,end+1};
                break;
            }
            else if(sum>target){
                end--;
            } 
            else{
                start++;
            }
        }
        return ans;
    }
};