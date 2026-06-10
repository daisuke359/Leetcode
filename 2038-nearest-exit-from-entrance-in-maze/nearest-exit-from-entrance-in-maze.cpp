class Solution {
public:
    struct Position {
        int row;
        int col;
        int steps;
    };
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        Position queue[10000];
        int front=0;
        int rear=0;

        int row_size=maze.size();
        int col_size=maze[0].size();

        int row_ent=entrance[0];
        int col_ent=entrance[1];

        //first push
        queue[rear].row=row_ent;
        queue[rear].col=col_ent;
        queue[rear].steps=0;
        rear++;

        maze[row_ent][col_ent] = '+';

        while(front < rear) {
            //pop
            Position current = queue[front];
            front++;

            if(!(current.row==row_ent && current.col==col_ent) && (current.row==0 || current.row==row_size-1 || current.col==0 || current.col==col_size-1)) {
                return current.steps;
            }

            if(current.row>0 && maze[current.row-1][current.col]=='.') {
                //make visited
                maze[current.row-1][current.col]='+';

                //push
                queue[rear].row=current.row-1;
                queue[rear].col=current.col;
                queue[rear].steps=current.steps+1;
                rear++;
            }

            if(current.row<row_size-1 && maze[current.row+1][current.col]=='.') {
                //make visited
                maze[current.row+1][current.col]='+';

                //push
                queue[rear].row=current.row+1;
                queue[rear].col=current.col;
                queue[rear].steps=current.steps+1;
                rear++;
            }

            if(current.col>0 && maze[current.row][current.col-1]=='.') {
                //make visited
                maze[current.row][current.col-1]='+';

                //push
                queue[rear].row=current.row;
                queue[rear].col=current.col-1;
                queue[rear].steps=current.steps+1;
                rear++;
            }

            if(current.col<col_size-1 && maze[current.row][current.col+1]=='.') {
                //make visited
                maze[current.row][current.col+1]='+';

                //push
                queue[rear].row=current.row;
                queue[rear].col=current.col+1;
                queue[rear].steps=current.steps+1;
                rear++;
            }

        }

        return -1;

    }
};