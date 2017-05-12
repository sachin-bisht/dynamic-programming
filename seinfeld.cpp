#include<iostream>
#include<string>
using namespace std;

int count(string&);
int main()
{
    string s;
    cin>>s;
    int i=1;
    while(s[0]!='-')
    {
        cout<<i<<". "<<count(s)<<endl;
        cin>>s;
        i++;
    }
    return 0;
}

int count(string &str)
{
    for(int i=0;i<str.size()-1;i++)
    {
        if(str[i]=='{' && str[i+1]=='}')
        {
            //cout<<str<<" "<<str.size()<<" "<<i<<"\t";
            str.erase(i,2);
            if(i==0)
                i--;
            else
                i-=2;
            //cout<<str<<" "<<str.size()<<" "<<i<<endl;
        }
        if(str.size()==0)
            return 0;
    }
    int c=0;
    for(int i=0;i<str.size()-1;i++)
    {
        if(str[i]=='{' && str[i+1]=='{')
        {
            c++;
            str.erase(i,2);
            i--;
            if(i!=0)
                i--;
            //cout<<str<<" "<<str.size()<<" "<<i<<endl;
        }
        else if(str[i]=='}' && str[i+1]=='}')
        {
            c++;
            str.erase(i,2);
            i--;
            if(i!=-1)
                i--;
            //cout<<str<<" "<<str.size()<<" "<<i<<endl;
        }
        if(str.size()==0)
            return c;
    }
    int k=str.size()/2;
    for(int i=1;i<=str.length()/2;i++)
    {
        if(str[k-i]=='{' && str[k+i-1]=='{')
            c++;
        else if(str[k-i]=='}' && str[k+i-1]=='}')
            c++;
        else if(str[k-i]=='}' && str[k+i-1]=='{')
            c+=2;
    }
    return c;
}
