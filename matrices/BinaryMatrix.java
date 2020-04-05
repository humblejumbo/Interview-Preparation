//https://classroom.codingninjas.com/app/classroom/me/1664/content/29763/offering/313151/problem/5432

import java.util.Scanner;

public class Main {

	
	public static void main(String[] args) {
		/* Your class should be named Main.
 			* Read input as specified in the question.
 			* Print output as specified in the question.
		*/

		// Write your code here
        
        boolean colfirst=false,rowfirst=false;
        Scanner s= new Scanner(System.in);
        int m,n;
        m=s.nextInt();
        n=s.nextInt();
        int[][] arr=new int[m][n];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                arr[i][j]=s.nextInt();
        }
        
        
        for(int i=0;i<m;i++)
        {
            if(arr[i][0]==1)
            {
                colfirst=true;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[0][i]==1)
            {
                rowfirst=true;
            }
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(arr[i][j]==1)
                {
                    arr[i][0]=1;
                    arr[0][j]=1;
                }
            }
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(arr[i][0]==1 || arr[0][j]==1)
                    arr[i][j]=1;
            }
        }
        
        if(colfirst==true)
        {
            for(int i=0;i<m;i++)
                arr[i][0]=1;
        }
        
        if(rowfirst==true)
        {
            for(int i=0;i<n;i++)
                arr[0][i]=1;
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                System.out.print(arr[i][j]+" ");
            
            System.out.print('\n');
        }

	}

}
