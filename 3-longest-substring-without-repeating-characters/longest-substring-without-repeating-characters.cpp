class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> count;
        int i=0,j=0,len=0;

        while(j<s.length()){
            count[s[j]]++;

            while(count[s[j]]>1){
                count[s[i]]--;
                
                if(count[s[i]] == 0){
                    count.erase(s[i]);
                }
                i++;
            }
            len = max(len,j-i+1);
            j++;
        }
        return len;
    }
};