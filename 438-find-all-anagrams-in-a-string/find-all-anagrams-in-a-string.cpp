class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> m;
        for(auto c: p){
            m[c]++;
        }
        int i=0,j=0,count=p.length();
        vector<int> ans;

        while(j<s.length()){
            if(m[s[j]]>0){
                count--;
            }
            m[s[j]]--;

            while(count == 0){

                if(j-i+1 == p.length()){
                    ans.push_back(i);
                }
                m[s[i]]++;

                if(m[s[i]]>0){
                    count++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};