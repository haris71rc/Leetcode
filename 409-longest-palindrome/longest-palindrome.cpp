class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0,taken=false;
        unordered_map<char,int> m;
        for(auto ch: s){
            m[ch]++;
        }
        if(m.size() == 1){
            for(auto e:m){
                return e.second;
            }
        }
        for(auto element:m){
            if(element.second%2 == 0){
                ans+=element.second;
            }
            else{
                ans+= element.second-1;
                taken = true;
            }
        }
        if(taken) ans+=1;
        return ans;
    }
};