//https://classroom.codingninjas.com/app/classroom/me/1664/content/47222/offering/537099/problem/1443

#include<bits/stdc++.h>
using namespace std;

int digits(int a)
{
    while(a)
    {
        if(a<10)
            return a;
        
        a/=10;
    }
    
}

void showJumpingNos(int x){
	
    vector<int> res;
    queue<int> q;
    
    res.push_back(0);
    
    for(int i=1;i<=9;i++)
    {
        if(i<=x)
        {
            res.push_back(i);
            q.push(i);
        }
        
        while(!q.empty())
        {
            int val=q.front()*10 + q.front()%10;
            q.pop();
            
            if(val+1<=x && val%10!=9)
            {
                res.push_back(val+1);
                q.push(val+1);
            }
            
            if(val-1<=x && val%10!=0)
            {
                res.push_back(val-1);
                q.push(val-1);
            }
        }
    }
    
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}
