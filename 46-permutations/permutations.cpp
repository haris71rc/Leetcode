class Solution {
private:
    void solve(vector<vector<int>> &ans, vector<int> &answer, vector<int>& nums, vector<bool> &used) {
        if(answer.size() == nums.size()) {
            ans.push_back(answer);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!used[i]) {
                used[i] = true;
                answer.push_back(nums[i]);
                solve(ans, answer, nums, used);
                answer.pop_back();
                used[i] = false;
            }
        }
    }    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> answer;
        vector<bool> used(nums.size(), false);
        solve(ans, answer, nums, used);
        return ans;
    }
};
