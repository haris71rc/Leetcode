class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;
        bool ans = true;
        for (int i = 0; i < magazine.size(); i++) {
            m[magazine[i]]++;
        }

        for (auto ele : ransomNote) {
            if (m.find(ele) != m.end() && m[ele] > 0) {
                
                m[ele]--;
            } else {
              return false;
            }
        }
        return ans;
    }
};