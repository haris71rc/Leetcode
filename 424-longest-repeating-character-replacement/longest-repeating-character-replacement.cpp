class Solution {
public:
    int characterReplacement(string s, int k) {
       map<char,int> count;
       int i=0,j=0,maxFreq=0,maxLen=0;

       while(j<s.length()){
        count[s[j] - 'A']++;
        maxFreq = max(maxFreq, count[s[j] - 'A']);

        if(((j-i+1) - maxFreq) > k){
            count[s[i]-'A']--;
            i++;
        }
        maxLen = max(maxLen, j-i+1);
        j++;
       } 
       return maxLen;
    }
};