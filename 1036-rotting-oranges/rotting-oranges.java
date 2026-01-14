class Solution {
    public int orangesRotting(int[][] grid) {
        int mins=0;
        int fresh=0;
        int rowLen=grid.length;
        int colLen=grid[0].length;

        //find a rotten orange
        Queue<int[]> queue = new LinkedList<>();
        for(int i=0;i<rowLen;i++) {
            for(int j=0;j<colLen;j++) {
                if(grid[i][j]==2) {
                    queue.add(new int[]{i,j});
                }
                if(grid[i][j]==1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;

        while(!queue.isEmpty() && fresh > 0) {
            int queueSize = queue.size();

            for(int m=0;m<queueSize;m++) {
                int[] elem = queue.poll();

                if(elem[0]-1>=0 && grid[elem[0]-1][elem[1]]==1) {
                    grid[elem[0]-1][elem[1]]=2;
                    fresh--;
                    queue.add(new int[]{elem[0]-1,elem[1]});
                }
                if(elem[0]+1 < rowLen && grid[elem[0]+1][elem[1]]==1) {
                    grid[elem[0]+1][elem[1]]=2;
                    fresh--;
                    queue.add(new int[]{elem[0]+1,elem[1]});
                }
                if(elem[1]-1>=0 && grid[elem[0]][elem[1]-1]==1) {
                    grid[elem[0]][elem[1]-1]=2;
                    fresh--;
                    queue.add(new int[]{elem[0],elem[1]-1});
                }
                if(elem[1]+1 < colLen && grid[elem[0]][elem[1]+1]==1) {
                    grid[elem[0]][elem[1]+1]=2;
                    fresh--;
                    queue.add(new int[]{elem[0],elem[1]+1});
                }
            }
            mins++;
        }
        return fresh == 0 ? mins : -1;
    }
}