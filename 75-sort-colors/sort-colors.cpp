class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros=0,ones=0,twos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                zeros++;
            }
            else if(nums[i]==1){
                ones++;
            }
            else{
                twos++;
            }
        }
        int i=0,j=0;
        while(i<zeros){
            nums[j] = 0;
            j++;
            i++;
        }
        i=0;
        while(i<ones){
            nums[j]=1;
            j++;
            i++;
        }
        i=0;
        while(i<twos){
            nums[j]=2;
             j++;
            i++;
        }
        return;
    }
};