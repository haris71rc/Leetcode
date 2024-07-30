class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(auto s:strs){
           string sortedString = s;
           sort(sortedString.begin(),sortedString.end());
           m[sortedString].push_back(s);
        }
        for(auto i: m){
            ans.push_back(i.second);
        }
        return ans;
    }
};