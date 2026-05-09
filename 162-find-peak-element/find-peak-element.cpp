class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        if (nums.size() == 2) {
            if (nums[0] > nums[1])
                return 0;
            else
                return 1;
        }

        while (low <= high) {
            int middle = low + (high - low) / 2;

            if (middle < n-1 && nums[middle] < nums[middle + 1]) {
                low = middle + 1;
            } else if (middle > 0 && nums[middle] < nums[middle - 1]) {
                high = middle - 1;
            } else {
                return middle;
            }
        }

        return 0;
    }
};