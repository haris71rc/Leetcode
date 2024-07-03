class Solution {
private:
    void solve(vector<vector<int>>&ans,vector<int> &output,int index,int target,vector<int>& candidates){
        
        if(index>=candidates.size() || target<0){
            return;
        }
        if(target==0){
            ans.push_back(output);
            return;
        }
        
            output.push_back(candidates[index]);
            solve(ans,output,index,target-candidates[index],candidates);
            output.pop_back();
            solve(ans,output,index+1,target,candidates);
            
        
    }    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> output;
        solve(ans,output,0,target,candidates);
        return ans;
    }
};