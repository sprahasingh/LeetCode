class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int s = INT_MAX;
        int l = INT_MIN;
        for(int num : nums){
            if(num < s) s = num;
            if(num > l) l = num;
        }
        return std::gcd(s,l);
    }
};