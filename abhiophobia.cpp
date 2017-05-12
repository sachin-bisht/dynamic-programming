#include<iostream>
#include<cstring>
using namespace std;
int mem[6101][6101];
int palin(string&,int,int);
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        memset(mem , -1 , sizeof mem);
        cout<<palin(s,0,s.size()-1)<<endl;
    }
    return 0;
}

int palin(string &s,int i,int j)
{
    if(i>=j)
        return 0;
    else{
        if(mem[i][j]!=-1)
        {
            return mem[i][j];
        }
        else if(s[i]!=s[j])
        {
                return mem[i][j]=min(palin(s,i,j-1),palin(s,i+1,j))+1;
        }
        else{
            return mem[i][j]=palin(s,i+1,j-1);
        }
    }
}
