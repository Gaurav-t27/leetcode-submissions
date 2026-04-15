class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++) {
            std::sort(grid[i].begin(),grid[i].end());
        }
        int sum = 0;
        for(int j=0;j<n;j++) {
            int maxCol = -1;
            for(int i=0;i<m;i++) {
                if(grid[i][j] > maxCol)
                    maxCol = grid[i][j];
            }
            sum += maxCol;
        }
        return sum;
    }
};