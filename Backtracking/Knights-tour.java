//https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

import java.io.*;
import java.util.*;
class GFG {
    
    public static boolean isSafe(int n,int[][] board,int row,int col)
    {
        if(row>=0 && col>=0 && row<n && col<n && board[row][col]==-1)
            return true;
        else
            return false;
    }
    
    public static boolean moveCounter(int[][] board,int moves,int row,int col)
    {
        int n=board.length;
        int[] movex={2, 1, -1, -2, -2, -1,  1,  2};
        int[] movey={1, 2,  2,  1, -1, -2, -2, -1};
        
        //System.out.println(moves-1+" "+row+" "+col);
        if(moves==n*n)
            return true;
            
        for(int i=0;i<8;i++)
        {
            if(isSafe(n,board,row+movex[i],col+movey[i])==true)
            {
                board[row+movex[i]][col+movey[i]]=moves;
                if(moveCounter(board,moves+1,row+movex[i],col+movey[i])==true)
                    return true;
                else
                    board[row+movex[i]][col+movey[i]]=-1;
            }
        }
        
        return false;
    }
    
    public static void knightTour(int[][] board)
    {
        int n=board.length;
        if(moveCounter(board,1,0,0)==true)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    System.out.print(board[i][j]+" ");
                
                System.out.println();
            }
        }
        else
            System.out.print("Unable to solve");
    }
	public static void main (String[] args) {
		
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[][] board=new int[n][n];
		
		for(int i=0;i<n;i++)
		{
		    for(int j=0;j<n;j++)
		        board[i][j]=-1;
		}
		
		board[0][0]=0;
		knightTour(board);
	}
}
