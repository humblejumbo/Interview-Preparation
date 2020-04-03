//https://www.geeksforgeeks.org/program-to-generate-all-possible-valid-ip-addresses-from-given-string-set-2/?ref=rp

//https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1#ExpectOP

//Remember in Ip address any block cannot be prefixed with 0.  xx.013.xx.xx(wrong), x.xxx.00.x(wrong), xx.0.x.xxx(right)

void genIp(string &s,vector<string> &result,int index,int count,string curr_ip)
{
    if(index==s.length() && count==4)
    {
        result.push_back(curr_ip);
        return;
    }
    
    if(index+1<s.length() && count<4)
    {
        curr_ip+=s.substr(index,1);
        curr_ip+='.';
        genIp(s,result,index+1,count+1,curr_ip);
        curr_ip.erase(curr_ip.end()-2,curr_ip.end());
    }
    
    if(index+2<s.length() && stoi(s.substr(index,2))>=10 && count<4)
    {
        curr_ip+=s.substr(index,2);
        curr_ip+='.';
        genIp(s,result,index+2,count+1,curr_ip);
        curr_ip.erase(curr_ip.end()-3,curr_ip.end());
    }
    
    if(index+3<s.length() && stoi(s.substr(index,3))>=100 && stoi(s.substr(index,3))<=255 &&  count<4)
    {
        curr_ip+=s.substr(index,3);
        curr_ip+='.';
        genIp(s,result,index+3,count+1,curr_ip);
        curr_ip.erase(curr_ip.end()-4,curr_ip.end());
    }
    
    if(count<4 && index<s.length() && stol(s.substr(index,s.length()-index))<=255)   //for the last block remember we don't need a '.' in this.
    {
        if(index==s.length()-1 && s[index]=='0')    //explicitly handing if the last character is 0. 
        {
            curr_ip+='0';
            genIp(s,result,index+1,count+1,curr_ip);
            //curr_ip.erase(curr_ip.end()-1,curr_ip.end());  //backtracking is not required here.
        }
        else if(s[index]!='0')
        {
            int pos=curr_ip.length()-1;
            curr_ip+=s.substr(index,s.length());
            genIp(s,result,s.length(),count+1,curr_ip);
            //curr_ip.erase(curr_ip.begin()+pos,curr_ip.end());   //backtracking is not required here.
        }

    }      
    
}

vector<string> genIp(string &s) {
    // Your code here
    
    vector<string> result;
    genIp(s,result,0,0,"");
    
    return result;
}
