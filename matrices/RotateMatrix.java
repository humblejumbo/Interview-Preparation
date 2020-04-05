//https://classroom.codingninjas.com/app/classroom/me/1664/content/29763/offering/313152/problem/696

public class Solution{

	public static void rotate(int input[][]){
		/* Your class should be named Solution
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
	 	 * Taking input and printing output is handled automatically.
		*/
        
        int n=input.length;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int temp=input[i][j];
                input[i][j]=input[j][i];
                input[j][i]=temp;
            }
        }
        
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<n;j++)
            {
                int temp=input[i][j];
                input[i][j]=input[n-1-i][j];
                input[n-1-i][j]=temp;
            }
        }
	}
}
