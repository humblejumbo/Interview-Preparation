//https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

//You have to print all paths
//One Line for every possible solution. 
//Every line will have N*N maze elements printed row wise and are separated by space. Only cells that are part of solution path should be 1, rest all cells should be 0.


public class Solution {
	
	    public static void ratInAMaze(int maze[][],int x,int y,int dest_x,int dest_y,int visited[][]){
        
        if(x==dest_x && y==dest_y)
        {
            visited[x][y]=1;
            
            for(int i=0;i<=dest_x;i++)
            {
                for(int j=0;j<=dest_y;j++)
                    System.out.print(visited[i][j]+" ");
            }
            
            System.out.println();
            visited[x][y]=0;
            return;
        }
            
        
        if(x>dest_x || y>dest_y || x<0 || y<0)
            return;
        
        if(maze[x][y]==0)
            return;
        
        if(visited[x][y]==1)
            return;
        
        visited[x][y]=1;
        
        ratInAMaze(maze,x+1,y,dest_x,dest_y,visited);         
        
        ratInAMaze(maze,x,y+1,dest_x,dest_y,visited);                
        
        ratInAMaze(maze,x-1,y,dest_x,dest_y,visited);
     
        ratInAMaze(maze,x,y-1,dest_x,dest_y,visited);
            
        visited[x][y]=0;
    }
	
	public static void ratInAMaze(int maze[][]){
		
	/* Your class should be named Solution.
	 * Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	 */
		
        int m=maze.length;
        int n=maze.length;        
        int visited[][]= new int [maze.length][maze.length];        
        ratInAMaze(maze,0,0,m-1,n-1,visited);
        
	}	
	
}
