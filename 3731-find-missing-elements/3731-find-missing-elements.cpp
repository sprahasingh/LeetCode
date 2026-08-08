class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int num = nums[0] + 1;
        vector<int> ans;
        for(int i = 1; i < n; ++i){
            while(nums[i] != num) ans.push_back(num++);
            num++;
        }
        return ans;
    }
};