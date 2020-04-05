//https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

//The output line contains true if any path exists for the rat to reach its destination otherwise print false.

public class Solution {
    
    public static boolean ratInAMaze(int maze[][],int x,int y,int dest_x,int dest_y,boolean visited[][]){
        
        if(x==dest_x && y==dest_y)
            return true;
        
        if(x>dest_x || y>dest_y || x<0 || y<0)
            return false;
        
        if(maze[x][y]==0)
            return false;
        
        if(visited[x][y]==true)
            return false;
        
        visited[x][y]=true;
        
        if(ratInAMaze(maze,x+1,y,dest_x,dest_y,visited)==true)
            return true;
        
        if(ratInAMaze(maze,x,y+1,dest_x,dest_y,visited)==true)
            return true;
        
        if(ratInAMaze(maze,x-1,y,dest_x,dest_y,visited)==true)
            return true;
        
        if(ratInAMaze(maze,x,y-1,dest_x,dest_y,visited)==true)
            return true;
        
        return false;
    }

	public static boolean ratInAMaze(int maze[][]){

		/*Your class should be named Solution. 
		*Don't write main().
	 	*Don't take input, it is passed as function argument.
	 	*Don't print output.
	 	*Taking input and printing output is handled automatically.
		*/ 
        
        int m=maze.length;
        int n=maze.length;        
        boolean visited[][]= new boolean [maze.length][maze.length];
        
        return ratInAMaze(maze,0,0,m-1,n-1,visited);
	}
}
