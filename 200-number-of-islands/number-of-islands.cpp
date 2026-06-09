class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int row_size = grid.size();
        int col_size = grid[0].size();

        if(r<0 || r>row_size-1 || c<0 || c>col_size-1) {
            return;
        }

        if(grid[r][c]=='0') {
            return;
        }

        grid[r][c]='0';

        dfs(grid, r-1,c);
        dfs(grid, r+1, c);
        dfs(grid, r, c-1);
        dfs(grid, r, c+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;

        int row_size = grid.size();
        int col_size = grid[0].size();

        for(int i=0;i<row_size;i++) {
            for(int j=0;j<col_size;j++) {
                if(grid[i][j]=='1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

};