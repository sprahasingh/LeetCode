class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n,-1);
        int maxi = INT_MIN;
        for(int i = 0; i < n; ++i){
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(maxi, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long ans = 0;
        for(int i = 0; i < n/2; ++i){
            ans += gcd(prefixGcd[i], prefixGcd[n-1-i]);
        }
        return ans;
    }
};