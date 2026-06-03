class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        for(auto c: s){
            if(!s1.empty() && c=='#'){
                s1.pop();
            }
            else if(c!='#') s1.push(c);
        }
        stack<char>s2;
        for(auto c: t){
            if(!s2.empty() && c=='#'){
                s2.pop();
            }
            else if(c!='#') s2.push(c);
        }

        while(!s1.empty() && !s2.empty()){
            if(s1.top()!=s2.top()) return false;
            s1.pop();
            s2.pop();
        }

        return s2.empty() && s1.empty() ? true:false; 


    }
};