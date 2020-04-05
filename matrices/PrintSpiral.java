//https://classroom.codingninjas.com/app/classroom/me/1664/content/29641/offering/311593/problem/389


public class solution {

	public static void spiralPrint(int matrix[][]){
		// Write your code here
        
        int row=matrix.length;
        int col=matrix[0].length;
        //boolean done=true;
        int k=0,n=0;                        //Refer code present in solution(more meaningful)
        
        while(true)
        {
           
            for(int i=0+k;i<col-k;i++)
            {
                System.out.print(matrix[0+k][i]+" ");
                n++;
            }
            
            if(n==row*col)
                break;
            
            for(int i=0+k+1;i<row-k;i++)
            {
                System.out.print(matrix[i][col-1-k]+" ");
                n++;
            }
            
            if(n==row*col)
                break;
            
            for(int i=col-2-k;i>=0+k;i--)
            {
                System.out.print(matrix[row-1-k][i]+" ");
                n++;
            }
            
            if(n==row*col)
                break;
            
            for(int i=row-2-k;i>=0+k+1;i--)
            {
                System.out.print(matrix[i][0+k]+" ");
                n++;
            }
            
            if(n==row*col)
                break;
            
            k++;
        }
        
	}
}
