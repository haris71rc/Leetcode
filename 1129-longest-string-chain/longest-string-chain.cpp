class Solution {
private:
    bool isPossible(string parent, string child) {
        int count = 0, j = 0;
        bool ans = false;
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == child[j])
                j++;
            else {
                count++;
            }
        }
        return parent.size() - child.size() == 1 && count == 1;
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        int maxLen = 1;
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPossible(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
            }
        }
        return maxLen;
    }
};