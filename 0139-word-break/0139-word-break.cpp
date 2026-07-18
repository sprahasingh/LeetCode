class Solution {
public:
    bool solve(string s, unordered_set<string>& occ, unordered_map<string,bool>& dp){
        if (s.empty()) return true;
        if (dp.count(s)) return dp[s];
        string word = "";
        for(int i = 0; i < s.size(); ++i){
            word += s[i];
            if(occ.count(word)){
                if(solve(s.substr(i + 1), occ, dp)){
                    dp[s] = true;
                    return true;
                }
                else dp[s] = false;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> occ(wordDict.begin(), wordDict.end());
        unordered_map<string,bool> dp(n+1);
        return solve(s, occ, dp);
    }
};