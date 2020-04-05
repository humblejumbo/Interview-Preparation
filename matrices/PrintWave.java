//https://classroom.codingninjas.com/app/classroom/me/1664/content/29641/offering/311593/problem/323

public class Solution {

	
	// input - input 2D array
	public static void wavePrint(int input[][]){
		
		// Write your code here
        int row=input.length;
        int col=input[0].length;
        
        for(int j=0;j<col;j++)
        {
            if(j%2==0)
            {
                for(int i=0;i<row;i++)
                {
                    System.out.print(input[i][j]+" ");
                }
            }
            else
            {
                for(int i=row-1;i>=0;i--)
                {
                    System.out.print(input[i][j]+" ");
                }
            }
        }

	}

	
}
