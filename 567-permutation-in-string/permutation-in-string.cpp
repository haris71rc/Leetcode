class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> m;
        int i = 0, j = 0, count = s1.length(), len = INT_MAX, startIndex = 0;

        for (auto c : s1) {
            m[c]++;
        }

        while (j < s2.length()) {
            if (m[s2[j]] > 0) {
                count--;
            }

            m[s2[j]]--;

            while (count == 0) {
                if (len > j - i + 1) {
                    len = min(len, j - i + 1);
                    startIndex = i;
                }
                m[s2[i]]++;
                if (m[s2[i]] > 0) {
                    count++;
                }
                i++;
            }
            j++;
        }
        cout<<"Start index "<< startIndex << " len "<< len<< "\n";
        return len == s1.length() ? true : false;
    }
};