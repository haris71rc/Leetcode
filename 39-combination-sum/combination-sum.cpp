class Solution {
private:
    void solve(vector<vector<int>> &ans, int index, vector<int> output, vector<int>& candidates, int target){
       if(index>=candidates.size() || target<0){
        return;
       } 
       if(target==0){
        ans.push_back(output);
        return;
       }

       output.push_back(candidates[index]);
       solve(ans,index,output,candidates,target-candidates[index]);
       output.pop_back();
       solve(ans,index+1,output,candidates,target);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int index=0;
        vector<int> output;

        solve(ans,index,output,candidates,target);

        return ans;
    }
};