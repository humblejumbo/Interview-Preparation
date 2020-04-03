//https://www.geeksforgeeks.org/boggle-find-possible-words-board-characters/

//It's more a graph dfs traversal but still I solved it using backtracking.

/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		while(t>0)
		{
     		int n=s.nextInt();
    	    String[] arr= new String[n];
    	    
    	    for(int i=0;i<n;i++)
    	        arr[i]=s.next();
    	        
    	   int m=s.nextInt();
    	   int k=s.nextInt();
    	   char[][] mat=new char[m][k];
    	   
    	   
    	   for(int i=0;i<m;i++)
    	   {
    	       for(int j=0;j<k;j++)
    	       {
    	           String st=s.next();
    	           mat[i][j]=st.charAt(0);
    	       }
    	   }
    	   
    	   int count=0;
    	   String[] result= new String[n];
    	   for(int i=0;i<n;i++)
    	   {
    	       int[][] visited= new int[m][k];
    	       
    	       int flag=0;
    	       for(int a=0;a<m;a++)         //Actually we have to pickup a starting point from the whole matrix. because it's not necessary 
    	       {                            // we can from a word by choosing starting point as 0,0.
    	           for(int b=0;b<k;b++)           
    	           {
    	                if(check(arr[i],mat,a,b,0,visited)==true)
    	                {
    	                    result[count++]=arr[i];
    	                    flag=1;
    	                    break;
    	                }
    	           }
    	           
    	           if(flag==1)
    	            break;
    	       }

    	   }
    	   
    	   if(count==0)
    	       System.out.print(-1);
    	   else
    	   {
    	       String[] res= new String[count];
    	       for(int i=0;i<count;i++)
    	            res[i]=result[i];
    	       Arrays.sort(res);
    	       String st=res[0];                        // we have to print the result acc. to dictionary i.e lexicographycally first and
    	       System.out.print(st+" ");                // no duplicates.
    	       for(int i=1;i<count;i++)
    	       {
    	           if(!res[i].equals(st))
    	           {
    	               System.out.print(res[i]+" ");
    	               st=res[i];
    	           }
    	            
    	       }
    	        
    	   }
    	   System.out.println();
    	   t--;
		}
		
	}
	
	
	private static boolean check(String s,char[][] mat,int x,int y,int count,int[][] visited)
	{
	    if(count==s.length())
	        return true;
	        
	    int[] move_r={1,-1,0,0,-1,-1,1,1,0};
	    int[] move_c={0,0,1,-1,-1,1,-1,1,0};
	    
	   //System.out.println(count+" "+x+" "+y);
	    for(int i=0;i<=8;i++)
	    {
	        if(isSafe(x+move_r[i],y+move_c[i],visited)==true)
	        {
	            
    	        if(mat[x+move_r[i]][y+move_c[i]]==s.charAt(count))
    	        {
    	            visited[x+move_r[i]][y+move_c[i]]=1;
    	            //System.out.println(mat[x+move_r[i]][y+move_c[i]]+" "+s.charAt(count));
    	           if(check(s,mat,x+move_r[i],y+move_c[i],count+1,visited)==true)
    	                return true;
        	       else
        	           visited[x+move_r[i]][y+move_c[i]]=0;
    	        }
    	        

	        }
	        
	    }
	    return false;
	}
	
	private static boolean isSafe(int x,int y,int[][] visited)
	{
	    int m=visited.length;
	    int n=visited[0].length;
	    
	    if(x>=0 && y>=0 && x<m && y<n && visited[x][y]==0)
	        return true;
	    else
	        return false;
	}
}
