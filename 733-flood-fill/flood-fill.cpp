class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int color, int orig_color) {
        int row_size=image.size();
        int col_size=image[0].size();


        cout << "checking" << endl;

        //top
        if(row-1>=0 && image[row-1][col]==orig_color) {
            image[row-1][col]=color;
            dfs(image, row-1, col, color, orig_color);
        }

        //top
        if(row+1<=row_size-1 && image[row+1][col]==orig_color) {
            image[row+1][col]=color;
            dfs(image, row+1, col, color, orig_color);
        }

        //top
        if(col-1>=0 && image[row][col-1]==orig_color) {
            image[row][col-1]=color;
            dfs(image, row, col-1, color, orig_color);
        }

        //top
        if(col+1<=col_size-1 && image[row][col+1]==orig_color) {
            image[row][col+1]=color;
            dfs(image, row, col+1, color, orig_color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row_size=image.size();
        int col_size=image[0].size();
        int orig_color=image[sr][sc];

        if(color==orig_color) {
            return image;
        }

        image[sr][sc]=color;
        dfs(image, sr, sc, color, orig_color);

        return image;
    }
};