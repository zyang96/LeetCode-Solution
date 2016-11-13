/*
Solution 1.
dp[i] means the string before element dp[i] can be word-broken, therefore, if dp[s.size()] is true, then the whole string can be word-broken
Time complexity: O(n^2)
Space complexity: O(n)	
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j]) {
                    string temp = s.substr(j, i - j);
                    if (wordDict.find(temp) != wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};