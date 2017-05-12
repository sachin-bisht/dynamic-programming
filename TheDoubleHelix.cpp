#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int largestsum(vector <int>,vector <int>);
int main()
{
    int a,b;
    cin>>a;
    while(a!=0)
    {
        vector <int> a1(a);
        for(int i=0;i<a;i++)
            cin>>a1[i];
        cin>>b;
        vector <int> b1(b);
        for(int i=0;i<b;i++)
            cin>>b1[i];
        cout<<largestsum(a1,b1)<<endl;
        cin>>a;
    }
    return 0;
}

int largestsum(vector <int> a,vector <int> b)
{
    int res=0;
    int s1,s2,k=0;
    int ele=0;
    s1=s2=0;
    for(int i=0;i<a.size();i++)
    {
        s2=0;
        s1+=a.at(i);
        for(int j=k;j<b.size();j++)
        {
            s2+=b.at(j);
            if(a.at(i)==b.at(j))
            {
                ele=a[i];
                k=j+1;
                //cout<<k<<" "<<s1<<" "<<s2<<endl;
                /*if(s1>s2)
                    res+=s1;
                else
                    res+=s2;*/
                    res=res+max(s1,s2);
                s1=0;
                break;
            }
        }
    }
    if(a[a.size()-1]!=b[b.size()-1])
    {
        int i=find(b.begin(),b.end(),ele)-b.begin();
        if(i<b.size()-1)
        {
            s2=0;
            i++;
            for(;i<b.size();i++)
                s2+=b[i];
        }
        //cout<<s1<<" V"<<s2<<endl;
        res=res+max(s1,s2);
    }
    return res;
}

