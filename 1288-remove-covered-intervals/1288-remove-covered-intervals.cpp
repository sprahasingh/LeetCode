class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int idx = 0;
        int count = n;
        for(int i = 1 ; i < n; ++i){
            if(intervals[i][0] == intervals[idx][0]) count--;
            else if(intervals[i][1] <= intervals[idx][1]) count--;
            else idx = i;
        }
        return count;
    }
};