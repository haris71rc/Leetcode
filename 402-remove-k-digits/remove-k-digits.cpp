class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        string ans;
        int n = num.size();

        for(int i=0;i<n;i++){
            char curr = num[i];
            while(!s.empty() && curr<s.top() && k>0){
                s.pop();
                k--;
            }

            s.push(curr);
        }

        while(k>0 && !s.empty()){
            s.pop();
            k--;
        }

        while(!s.empty()){
            ans += s.top();
            s.pop();
        }

        reverse(ans.begin(),ans.end());

         // Remove leading zeros
        size_t pos = ans.find_first_not_of('0');
        ans = (pos == std::string::npos) ? "0" : ans.substr(pos);

        return ans;
    }
};