//https://practice.geeksforgeeks.org/problems/special-matrix/0

/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		
		Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		
		while(t>0)
		{
		    int n=s.nextInt();
    		int m=s.nextInt();
    		int k=s.nextInt();
		
    		int[][] input= new int[n][m];
    		
    		for(int i=0;i<k;i++)
    		{
    		    int a=s.nextInt()-1;
    		    int b=s.nextInt()-1;
    		    input[a][b]=-1;
    		}
    		
    		long[][] mat= new long[n][m];
    		
    		mat[0][0]=1;   //no. of ways to reach starting point=1.
    		
    		for(int i=1;i<n;i++)        //There is only one way to reach the cells of first row i.e by right movement.
    		{
    		    if(input[i][0]!=-1)           
    		        mat[i][0]=mat[i-1][0];
    		}
    		
    		for(int i=1;i<m;i++)       //There is only one way to reach the cells of first column i.e by down movement.
    		{
    		    if(input[0][i]!=-1)
    		        mat[0][i]=mat[0][i-1];
    		}
    		
    		for(int i=1;i<n;i++)  // For rest of the cells,no of ways to reach it will be the sum of no. of ways to mat[i][j-1] cell +mat[i-1][j] cell.
    		{
    		    for(int j=1;j<m;j++)
    		    {
    		        if(input[i][j]!=-1)
    		            mat[i][j]=(mat[i-1][j]+mat[i][j-1])%1000000007;
    		    }
    		}
    		
    		System.out.println(mat[n-1][m-1]);
    		t--;
		}
		
		
	}
}