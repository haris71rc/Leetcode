class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_map<int, int> num_map; // map to store number and its index
        for (int i = 0; i < nums.size(); i++) {
            if (num_map.find(nums[i]) != num_map.end()) {
                if (i - num_map[nums[i]] <= k) {
                    return true;
                }
            }
            num_map[nums[i]] = i; // update the index of the number
        }
        return false;
         
    }
};