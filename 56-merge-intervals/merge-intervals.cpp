class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        // Sort intervals based on the starting value
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);  // Start with the first interval
        
        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval overlaps with the last interval in ans
            if (intervals[i][0] <= ans.back()[1]) {
                // Merge the intervals by updating the end time of the last interval
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                // If no overlap, add the current interval to the result
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};
