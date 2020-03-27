/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    
    public static boolean safeToPlace(int grid[][],int row,int col,int num)
    {
        
        for(int i=0;i<9;i++)
        {
            if(grid[row][i]==num)
                return false;
        }
        
        for(int i=0;i<9;i++)
        {
            if(grid[i][col]==num)
                return false;
        }
        
        int m= row-row%3;
        int n= col-col%3;
        
        for(int i=m;i<m+3;i++)
        {
            for(int j=n;j<n+3;j++)
            {
                if(grid[i][j]==num)
                    return false;
            }
        }
        
        return true;
        
    }

    public static boolean placeNumber(int[][] grid,int row,int col)
    {
        
        for(int i=row;i<grid.length;i++,col=0)
        {
            for(int j=col;j<grid[0].length;j++)
            {
                if(grid[i][j]==0)
                {
                    for(int k=1;k<=9;k++) //trial. Try 1 through 9
                    {
                        if(safeToPlace(grid,i,j,k)==true)
                        {
                            grid[i][j]=k;   //Put k for this cell
                            if(placeNumber(grid,i,j+1)==true) //If it's the solution return true
                                return true;
                            else
                                grid[i][j]=0;  //Otherwise go back
                        }
                    }
                    
                    return false;
                }
            }
        }
        return true;
        
    }
    
    public static void sudokuSolve(int[][] grid)
    {
        if(placeNumber(grid,0,0)==true)
        {
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    System.out.print(grid[i][j]+" ");
                }
                System.out.println();
            }
        }
        
        else
            System.out.print("Unable to solve sudoku");
    }
    
	public static void main (String[] args) {
		
		// 9x9 2-D matrix, fill 1-9 in all elements such that:
		// - numbers are unique in each row
		// - numbers are unique in each col
		// - numbers are unique in each 3x3 box
		
		int[][] grid = {
			{3, 0, 6, 5, 0, 8, 4, 0, 0},  
            {5, 2, 0, 0, 0, 0, 0, 0, 0},  
            {0, 8, 7, 0, 0, 0, 0, 3, 1},  
            {0, 0, 3, 0, 1, 0, 0, 8, 0},  
            {9, 0, 0, 8, 6, 3, 0, 0, 5},  
            {0, 5, 0, 0, 9, 0, 6, 0, 0},  
            {1, 3, 0, 0, 0, 0, 2, 5, 0},  
            {0, 0, 0, 0, 0, 0, 0, 7, 4},  
            {0, 0, 5, 2, 0, 6, 3, 0, 0}	
		};
		sudokuSolve(grid);
		
	}
}