//https://www.geeksforgeeks.org/combinational-sum/

//https://practice.geeksforgeeks.org/problems/combination-sum/0


#include <bits/stdc++.h>
using namespace std;

void combination(vector<int> arr,int target,int index,vector<int> v,bool& isEmpty)
{
    if(target==0)
    {
        cout<<"(";
        for(int i=0;i<v.size()-1;i++)
            cout<<v[i]<<" ";
        cout<<v[v.size()-1]<<")";
        
        v.clear();
        isEmpty=false;
        return;
    }
    
    if(target<0)
        return;
        
        
    while(index<arr.size() && target-arr[index]>=0)
    {

        v.push_back(arr[index]);
        
        combination(arr,target-arr[index],index,v,isEmpty);
        index++;
        
        v.pop_back();
        
    }
    
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,target;
	    cin>>n;
	    
	    vector<int> arr(n);
	    
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	      
      //Sorting the input array and removing the duplicates.
	   sort(arr.begin(),arr.end());
	   auto it=unique(arr.begin(),arr.end());  
	   arr.resize( distance(arr.begin(),it) );
	   n=distance(arr.begin(),it);
     
	   cin>>target;
	   vector<int> v;
	   bool isEmpty=true;
	   
	   combination(arr,target,0,v,isEmpty);
	   if(isEmpty==true)
	        cout<<"Empty"<<endl;
	   else
	        cout<<endl;
	   
	}

	return 0;
}
