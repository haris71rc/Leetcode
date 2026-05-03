class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        int n = temperatures.size();
        vector<int> ans(n,0);

        for(int i=n-1;i>=0;i--){
            int curr = temperatures[i];
            while(!s.empty() && curr>=s.top().first){
                s.pop();
            }
            
            if(!s.empty()){
                ans[i] = s.top().second - i;
            }

            s.push({curr,i});

        }
        return ans;
    }
};