class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int idx, int gcd1, int gcd2, vector<int>& nums, vector<vector<vector<int>>>& dp){
        if(dp[idx][gcd1][gcd2] != -1) return dp[idx][gcd1][gcd2];
        if(idx == nums.size()) return (gcd1 > 0 && gcd2 > 0 && gcd1 == gcd2);
        
        int ans = 0;
        ans = (ans + solve(idx + 1, std::gcd(gcd1,nums[idx]), gcd2, nums, dp)) % MOD;
        ans = (ans + solve(idx + 1, gcd1, std::gcd(gcd2,nums[idx]), nums, dp)) % MOD;
        ans = (ans + solve(idx + 1, gcd1, gcd2, nums, dp)) % MOD;
        dp[idx][gcd1][gcd2] = ans;
        return ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int idx = 0, gcd1 = 0, gcd2 = 0;
        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(201,
                vector<int>(201, -1)
            )
        );
        return solve(idx, gcd1, gcd2, nums, dp);
    }
};