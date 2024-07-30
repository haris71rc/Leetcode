class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m;
        if(s.size()!=t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            m[t[i]]--;
        }
        for (auto i : m) {
            if (i.second != 0)
                return false;
        }
        return true;
    }
};