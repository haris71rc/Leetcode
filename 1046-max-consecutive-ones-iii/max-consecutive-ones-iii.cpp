class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      
        int i = 0, j = 0, maxFreq = 0, maxLen = 0;

        while (j < nums.size()) {
            if(nums[j] ==0){
                maxFreq++;
            }
            while( maxFreq> k) {
                if(nums[i] ==0){
                maxFreq--;
            }
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};