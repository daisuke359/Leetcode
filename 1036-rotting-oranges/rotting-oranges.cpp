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

        bool hasFresh=false;
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
                    hasFresh=true;
                }
            }
        }

        //check if there is no fresh orange
        if(!hasFresh) {
            return 0;
        }

        while(front<rear) {
            //pop
            Position current = queue[front];
            front++;

            //check if every orange is rotten
            bool allRotten=true;
            for(int i=0;i<row_size;i++) {
                for(int j=0;j<col_size;j++) {
                    if(grid[i][j]==1) {
                        allRotten=false;
                        break;
                    }
                }
            }

            if(allRotten && front==rear) {
                return current.mins;
            }
            

            //top
            if(current.row>0 && grid[current.row-1][current.col]==1) {
                //mark rotten
                grid[current.row-1][current.col]=2;

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

                //push
                queue[rear].row=current.row;
                queue[rear].col=current.col+1;
                queue[rear].mins=current.mins+1;
                rear++;
            }

        }

        return -1;
    }
};