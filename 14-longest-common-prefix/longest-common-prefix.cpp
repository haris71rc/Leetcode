class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs[0].size();
        bool yes=false;
        for(int i=0;i<n;i++){
            for(int j=1;j<strs.size();j++){
                if(strs[0][i]==strs[j][i]){
                    yes=true;
                }
                else{
                    return ans;
                }
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};