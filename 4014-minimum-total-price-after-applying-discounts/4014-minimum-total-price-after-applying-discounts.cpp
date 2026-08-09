class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());
        double ans = 0;
        for(int i = 0; i < n; ++i){
            if(i < m) ans += (prices[i]*(100-discounts[i]))/100.0;
            else ans += prices[i];
        }
        return ans;
    }
};