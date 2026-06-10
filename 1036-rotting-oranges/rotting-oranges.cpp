class Solution {
public:
    struct Position {
        int row;
        int col;
        int mins;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int row_size=grid.size();
        int col_size=grid[0].size();

        Position queue[10000];
        int front=0;
        int rear=0;

        int mins=0;

        int freshCount=0;
        //first pushes
        for(int i=0;i<row_size;i++) {
            for(int j=0;j<col_size;j++) {
                if(grid[i][j]==2) {
                    queue[rear].row=i;
                    queue[rear].col=j;
                    queue[rear].mins=0;
                    rear++;
                }

                if(grid[i][j]==1) {
                    freshCount++;
                }
            }
        }

        //check if there is no fresh orange
        if(freshCount==0) {
            return 0;
        }

        while(front<rear) {
            //pop
            Position current = queue[front];
            front++;

            mins = current.mins;
            
            //top
            if(current.row>0 && grid[current.row-1][current.col]==1) {
                //mark rotten
                grid[current.row-1][current.col]=2;
                freshCount--;

                //push
                queue[rear].row=current.row-1;
                queue[rear].col=current.col;
                queue[rear].mins=current.mins+1;
                rear++;
            }

            //bottom
            if(current.row<row_size-1 && grid[current.row+1][current.col]==1) {
                //mark rotten
                grid[current.row+1][current.col]=2;
                freshCount--;

                //push
                queue[rear].row=current.row+1;
                queue[rear].col=current.col;
                queue[rear].mins=current.mins+1;
                rear++;
            }

            //left
            if(current.col>0 && grid[current.row][current.col-1]==1) {
                //mark rotten
                grid[current.row][current.col-1]=2;
                freshCount--;

                //push
                queue[rear].row=current.row;
                queue[rear].col=current.col-1;
                queue[rear].mins=current.mins+1;
                rear++;
            }

            //right
            if(current.col<col_size-1 && grid[current.row][current.col+1]==1) {
                //mark rotten
                grid[current.row][current.col+1]=2;
                freshCount--;

                //push
                queue[rear].row=current.row;
                queue[rear].col=current.col+1;
                queue[rear].mins=current.mins+1;
                rear++;
            }

        }

        if(freshCount!=0) {
            return -1;
        } else {
            return mins;
        }
    }
};