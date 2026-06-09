class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int row_size = grid.size();
        int col_size = grid[0].size();
        if(r<0 || r>=row_size || c<0 || c>=col_size) {
            return 0;
        }

        if(grid[r][c]==0) {
            return 0;
        }

        grid[r][c]=0;
        return dfs(grid, r-1, c) + dfs(grid, r+1, c) + dfs(grid, r, c-1) + dfs(grid, r, c+1) + 1;

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
        int maxArea=0;
        int row_size = grid.size();
        int col_size = grid[0].size();

        for(int i=0;i<row_size;i++) {
            for(int j=0;j<col_size;j++) {
                if(grid[i][j]==1) {
                    count = dfs(grid, i, j);
                    if(count>maxArea) {
                        maxArea=count;
                    }
                }
            }
        }

        return maxArea;

    }
};