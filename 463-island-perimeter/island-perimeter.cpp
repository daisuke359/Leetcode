class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int param = 0;
        int row_size=grid.size();
        int col_size=grid[0].size();

        //top
        if(row-1>=0 && grid[row-1][col]==1) {
            grid[row-1][col]=2;
            param+=dfs(grid, row-1, col);
        } else if(row-1<0 || grid[row-1][col]==0) {
            param++;
        }

        //bottom
        if(row+1<=row_size-1 && grid[row+1][col]==1) {
            grid[row+1][col]=2;
            param+=dfs(grid, row+1, col);
        } else if(row+1>row_size-1 || grid[row+1][col]==0){
            param++;
        }

        //left
        if(col-1>=0 && grid[row][col-1]==1) {
            grid[row][col-1]=2;
            param+=dfs(grid, row, col-1);
        } else if(col-1<0 || grid[row][col-1]==0) {
            param++;
        }

        //right
        if(col+1<=col_size-1 && grid[row][col+1]==1) {
            grid[row][col+1]=2;
            param+=dfs(grid, row, col+1);
        } else if(col+1>col_size-1 || grid[row][col+1]==0) {
            param++;
        }

        return param;
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row_size=grid.size();
        int col_size=grid[0].size();
        
        for(int i=0;i<row_size;i++) {
            for(int j=0;j<col_size;j++) {
                if(grid[i][j]==1) {
                    grid[i][j]=2;
                    return dfs(grid, i, j); 
                }
            }
        }

        return -1;
    }
};