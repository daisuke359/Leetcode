class Solution {
public:
    struct Position {
        int row;
        int col;
        int steps;
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row_size = grid.size();
        int col_size = grid[0].size();

        Position queue[100000];
        int front = 0;
        int rear = 0;

        if(grid[0][0]!=0) {
            return -1;
        }

        //first push
        queue[0].row=0;
        queue[0].col=0;
        queue[0].steps=0;
        rear++;

        int count=0;
        while(front<rear) {
            //pop
            Position current = queue[front];
            front++;
            count++;

            int row=current.row;
            int col=current.col;
            int steps=current.steps;

            if(row==row_size-1 && col==col_size-1) {
                return steps+1;
            }

            // Top

            if(row-1>=0 && grid[row-1][col]==0) {

                grid[row-1][col]=1;

                queue[rear].row=row-1;

                queue[rear].col=col;

                queue[rear].steps=steps+1;

                rear++;

            }

            // Bottom

            if(row+1<row_size && grid[row+1][col]==0) {

                grid[row+1][col]=1;

                queue[rear].row=row+1;

                queue[rear].col=col;

                queue[rear].steps=steps+1;

                rear++;

            }

            // Left

            if(col-1>=0 && grid[row][col-1]==0) {

                grid[row][col-1]=1;

                queue[rear].row=row;

                queue[rear].col=col-1;

                queue[rear].steps=steps+1;

                rear++;

            }

            // Right

            if(col+1<col_size && grid[row][col+1]==0) {

                grid[row][col+1]=1;

                queue[rear].row=row;

                queue[rear].col=col+1;

                queue[rear].steps=steps+1;

                rear++;

            }

            // Top Left

            if(row-1>=0 && col-1>=0 && grid[row-1][col-1]==0) {

                grid[row-1][col-1]=1;

                queue[rear].row=row-1;

                queue[rear].col=col-1;

                queue[rear].steps=steps+1;

                rear++;

            }

            // Top Right

            if(row-1>=0 && col+1<col_size && grid[row-1][col+1]==0) {

                grid[row-1][col+1]=1;

                queue[rear].row=row-1;

                queue[rear].col=col+1;

                queue[rear].steps=steps+1;

                rear++;

            }

            // Bottom Left

            if(row+1<row_size && col-1>=0 && grid[row+1][col-1]==0) {

                grid[row+1][col-1]=1;

                queue[rear].row=row+1;

                queue[rear].col=col-1;

                queue[rear].steps=steps+1;

                rear++;

            }

            // Bottom Right

            if(row+1<row_size && col+1<col_size && grid[row+1][col+1]==0) {

                grid[row+1][col+1]=1;

                queue[rear].row=row+1;

                queue[rear].col=col+1;

                queue[rear].steps=steps+1;

                rear++;

            }

        }

        return -1;
   
    }

    
};