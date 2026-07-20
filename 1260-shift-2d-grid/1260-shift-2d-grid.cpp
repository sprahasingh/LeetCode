class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> temp(grid);
        for(int times = 0; times < k; ++times){
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(j == n-1){
                        if(i == m-1) grid[0][0] = temp[m-1][n-1];
                        else grid[i+1][0] = temp[i][n-1];
                    }
                    else grid[i][j+1] = temp[i][j];
                }
            }
            temp = grid;
        }
        return grid;
    }
};