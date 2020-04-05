//https://practice.geeksforgeeks.org/problems/combination-sum-part-2/0

//We should not remove duplicates from the input array unlike what we did in combination-sum-I.

#include <bits/stdc++.h>
using namespace std;

void combination(vector<int> arr,int target,int index,vector<int> v,set<vector<int> >&res)
{
    if(target==0)
    {
        res.insert(v);
        v.clear();
        return;
    }
    
    if(target<0)
        return;
        
        
    while(index<arr.size() && target-arr[index]>=0)
    {

        v.push_back(arr[index]);
        
        combination(arr,target-arr[index],index+1,v,res);
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
	        
	   sort(arr.begin(),arr.end());
	   cin>>target;
	   vector<int> v;
	   set<vector<int> > res;  // We have to use set here because same combination subset are appearing in result beause of the duplicate
	                                        //values present in input array.
	   combination(arr,target,0,v,res);
	   if(!res.size())
	        cout<<"Empty"<<endl;
	   else
	   {
	       while(res.size())
	       {
	           vector<int> v1= *(res.begin());
	           	cout<<"(";
                for(int i=0;i<v1.size()-1;i++)
                    cout<<v1[i]<<" ";
                cout<<v1[v1.size()-1]<<")";
                res.erase(res.begin());
	       }
            cout<<endl;
	   }
	   
	}

	return 0;
}
