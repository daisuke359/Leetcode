class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        cout << "1 detected! row: " + to_string(row) + " col: " + to_string(col) << endl;
        int row_size=grid.size();
        int col_size=grid[0].size();
        int top=0;
        int bottom=0;
        int left=0;
        int right = 0;

        if((row-1<0 || grid[row-1][col]==0)&&(row+1>=row_size || grid[row+1][col]==0)&&(col-1<0 || grid[row][col-1]==0)&&(col+1>=col_size || grid[row][col+1]==0)) {
            return 1;
        }

        //top
        if(row-1>=0 && grid[row-1][col]==1) {
            grid[row-1][col]=0;
            top = dfs(grid, row-1, col);
        }
        //bottom
        if(row+1<=row_size-1 && grid[row+1][col]==1) {
            grid[row+1][col]=0;
            //return dfs(grid, row+1, col) + 1;
            bottom = dfs(grid, row+1, col);
        }
        //left
        if(col-1>=0 && grid[row][col-1]==1) {
            grid[row][col-1]=0;
            left = dfs(grid, row, col-1);
        }
        //right
        if(col+1<=col_size-1 && grid[row][col+1]==1) {
            grid[row][col+1]=0;
            right = dfs(grid, row, col+1);
        }

        return top + bottom + left + right + 1;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row_size=grid.size();
        int col_size=grid[0].size();
        int count=0;
        int maxArea=0;

        for(int i=0;i<row_size;i++) {
            for(int j=0;j<col_size;j++) {
                if(grid[i][j]==1) {
                    grid[i][j]=0;
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