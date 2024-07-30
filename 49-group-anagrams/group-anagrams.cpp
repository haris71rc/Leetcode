class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++){
           string sortedString = strs[i];
           sort(sortedString.begin(),sortedString.end());
           m[sortedString].push_back(strs[i]);
        }
        for(auto i: m){
            ans.push_back(i.second);
        }
        return ans;
    }
};