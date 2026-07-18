class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen(nums.begin(), nums.end());
        for(int i = 1; i <= n+1; ++i){
            if(!seen.count(i)) return i;
        }
        return -1;
    }
};