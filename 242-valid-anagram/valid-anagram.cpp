class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(m[t[i]]!=0){
                m[t[i]]--;
            }
            else{
                return false;
            }
        }
        for(auto i:m){
            if(i.second!=0) return false;
        }
        return true;
    }
};