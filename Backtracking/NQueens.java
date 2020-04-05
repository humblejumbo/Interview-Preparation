//https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
//Print all configurations


public class Solution {
	
		
public static void placeNQueens(int n){
		
	/* Your class should be named Solution.
	 * Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	 */

        int board[][]=new int [n][n];
        placeQueens(n,0,board);
	}
    
    public static void placeQueens(int n,int row,int[][] board)
    {
        if(row==n)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    System.out.print(board[i][j]+" ");
            }
            System.out.println();
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isBoardSafe(row,i,board)==true)
            {
                board[row][i]=1;
                placeQueens(n,row+1,board);
                board[row][i]=0;   //backtracking
            }
        }
        
    }
    
    public static boolean isBoardSafe(int row,int col,int[][] board)
    {
        int n=board.length;        
        
        int flag=0;
        for(int j=row-1;j>=0;j--)     // checking queen in same column above this row.
        {
            if(board[j][col]==1)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
            return false;

        for(int j=row-1,k=col+1;j>=0 && k<n;j--,k++)      // checking queen in right diagonal above this row.
        {
            if(board[j][k]==1)
            {
                flag=1;
                break;
            }
        }
        
        if(flag==1)
            return false;


        for(int j=row-1,k=col-1;j>=0 && k>=0;j--,k--)     // checking queen in left diagonal above this row.
        {
            if(board[j][k]==1)
            {
                flag=1;
                break;
            }
        }
        
        if(flag==1)
            return false;
        else
            return true;                
        
    }
	
}
