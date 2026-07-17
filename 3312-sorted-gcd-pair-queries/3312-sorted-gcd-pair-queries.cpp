class Solution {
public:
    long long nc2(long long n) {
        if (n < 2) return 0;
        return n * (n - 1) / 2;
    }
    int find(vector<long long>& gcd, long long target) {
        int low = 0;
        int high = gcd.size() - 1;
        int ans = gcd.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (gcd[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } 
            else low = mid + 1;
        }
        return ans;
    }
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int m = queries.size();
        unordered_map<int,int> freq;
        int maxi = 1;
        for(int num : nums){
            freq[num]++;
            maxi = max(maxi, num);
        }
        vector<int> div(maxi+1, 0);
        for(int i = 1; i <= maxi; ++i){
            div[i] = 0;
            for(int j = i; j <= maxi; j += i){
                div[i] += freq[j];
            }
        }
        vector<long long> gcd(maxi+1, 0);
        for(int i = 0; i <= maxi; ++i){
            gcd[i] = nc2(div[i]);
        }
        for(int i = maxi; i > 0; i--){
            for(int j = 2*i; j <= maxi; j += i){
                gcd[i] -= gcd[j];
            }
        }
        for(int i = 1; i <= maxi; ++i){
            gcd[i] = gcd[i-1] + gcd[i];
        }
        vector<int> ans(m,0);
        for(int i = 0; i < m; ++i){
            ans[i] = find(gcd,queries[i]+1);
        }
        return ans;
    }
};