class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> m;
        for(auto c: t){
            m[c]++;
        }

        int i=0,j=0,count=t.length(),startIndex=0,minLen=INT_MAX;

        while(j<s.length()){

            if(m[s[j]]>0){
                count--;
            }
            m[s[j]]--;

            while(count == 0){

                if(minLen>j-i+1){
                    minLen = j-i+1;
                    startIndex = i;
                }

                m[s[i]]++;
                if(m[s[i]]>0){
                    count++;
                }
                i++;
            }

            j++;
        }

        return minLen == INT_MAX? "": s.substr(startIndex,minLen);
    }
};