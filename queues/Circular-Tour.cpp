//https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   //Your code here
   int start=0;
   int end=1;
   int curr_petrol=p[0].petrol-p[0].distance;
   
   while(start!=end || curr_petrol<0)
   {
       while(start!=end && curr_petrol<0)
       {
           curr_petrol-=p[start].petrol-p[start].distance;
           start=(start+1)%n;
           
           if(start==0)
                return -1;
       }
       
       curr_petrol+=p[end].petrol-p[end].distance;
       end=(end+1)%n;
   }
   
   return start;
}

