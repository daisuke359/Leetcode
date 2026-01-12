class Solution {
    public int numIslands(char[][] grid) {
        int count  = 0;
        int rowLen = grid.length;
        int colLen = grid[0].length;

        for(int i=0;i<rowLen;i++) {
            for(int j=0;j<colLen;j++) {
                if(grid[i][j]=='1') {
                    count++;

                    Queue<int[]> queue = new LinkedList<>();

                    queue.add(new int[]{i,j});

                    while(!queue.isEmpty()) {
                        int[] elem = queue.poll();

                        //grid[elem[0]][elem[1]] = '0';

                        if(elem[0]-1>=0 && grid[elem[0]-1][elem[1]]=='1') {
                            grid[elem[0]-1][elem[1]]='0';
                            queue.add(new int[]{elem[0]-1,elem[1]});
                        }
                        if(elem[0]+1 < rowLen && grid[elem[0]+1][elem[1]]=='1') {
                            grid[elem[0]+1][elem[1]]='0';
                            queue.add(new int[]{elem[0]+1,elem[1]});
                        }
                        if(elem[1]-1>=0 && grid[elem[0]][elem[1]-1]=='1') {
                            grid[elem[0]][elem[1]-1]='0';
                            queue.add(new int[]{elem[0],elem[1]-1});
                        }
                        if(elem[1]+1 < colLen && grid[elem[0]][elem[1]+1]=='1') {
                            grid[elem[0]][elem[1]+1]='0';
                            queue.add(new int[]{elem[0],elem[1]+1});
                        }
                        
                    }

                    
                }
            }
            
        }

        return count;
        
    }

}