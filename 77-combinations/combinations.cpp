class Solution {
private:
    void solve(int n,int k,vector<vector<int>> &ans,int index,vector<int> &answer){
        if(answer.size()==k){
            ans.push_back(answer);
            return;
        }

        for(int i=index;i<=n;i++){
            answer.push_back(i);
            solve(n,k,ans,i+1,answer);
            answer.pop_back();
        }
    }    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int> answer;

        solve(n,k,ans,1,answer);
        return ans;
    }
};