class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_map<char,int>m;
        int start=0,len=INT_MIN;
        for(int end=0;end<s.size();end++){
            if(m.find(s[end])!=m.end()){
                start=max(start,m[s[end]]+1);
            }
            m[s[end]]=end;
            len = max(len,end-start+1);
        }
        return len;
    }
};