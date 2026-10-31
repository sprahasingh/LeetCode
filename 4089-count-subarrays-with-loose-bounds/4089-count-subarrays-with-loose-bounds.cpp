class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long i = 0, j = 0, ans = 0;
        while(j < n){
            if(j == n-1 && (nums[j] >= minK && nums[j] <= maxK)){
                ans += ((j-i+1)*(j-i+2))/2;
            }
            if(nums[j] < minK || nums[j] > maxK){
                ans += ((j-i)*(j-i+1))/2;
                i = j+1;
            }
            j++;
        }
        return ans;
    }
};