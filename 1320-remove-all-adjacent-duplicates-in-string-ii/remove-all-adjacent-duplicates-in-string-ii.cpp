class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        string ans = "";
        for(int i=0;i<s.size();i++){
            int curr = s[i];

            if(stk.empty() || curr!=stk.top().first){
                stk.push({curr,1});
            }
            else{
                auto element = stk.top();
                stk.pop();
                stk.push({curr,element.second +1});
            }
            if(stk.top().second == k) stk.pop();
        }

        while(!stk.empty()){
            auto curr = stk.top();
            stk.pop();

            while(curr.second--){
                ans.push_back(curr.first);
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;


    }
};