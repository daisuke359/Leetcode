class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int original_color) {
        int row_size=image.size();
        int col_size=image[0].size();
        if(r<0 || r>row_size-1 || c<0 || c>col_size-1) {
            return;
        }

        if(image[r][c]!=original_color) {
            return;
        }

        image[r][c]=color;

        dfs(image, r-1,c,color, original_color);
        dfs(image, r+1,c,color, original_color);
        dfs(image, r,c-1,color, original_color);
        dfs(image, r,c+1,color, original_color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row_size=image.size();
        int col_size=image[0].size();
        int original_color = image[sr][sc];

        if (original_color == color) {
            return image;
        }

        dfs(image, sr, sc, color, original_color);

        return image;
    }
};