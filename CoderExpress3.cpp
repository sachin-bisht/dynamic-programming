#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int bitonicseq(vector <int> vec);
int main()
{
    int t;
    cin>>t;
    for(int a0=0;a0<t;a0++)
    {
        int len;
        cin>>len;
        vector <int> vec(len);
        for(int  i=0;i<len;i++)
            cin>>vec[i];
        cout<<bitonicseq(vec)<<endl;
    }
}

int bitonicseq(vector <int> vec)
{
    int lis[vec.size()],lds[vec.size()];
    for(int i=0;i<vec.size();i++){
        lis[i]=1;
        lds[i]=1;
    }
    //memset(lis,1,vec.size());
    //memset(lds,1,vec.size());
    for(int i=1;i<vec.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(vec[i]>vec[j] && lis[i] < lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    for(int i=vec.size()-2;i>=0;i--)
    {
        for(int j=vec.size()-1;j>i;j--)
        {
            if(vec[i]>vec[j] && lds[i] < lds[j]+1)
                lds[i]=lds[j]+1;
        }
    }
    int res=lis[0]+lds[0]-1;
    for(int i=1;i<vec.size();i++)
    {
        if(res<lis[i]+lds[i]-1)
            res=lis[i]+lds[i]-1;
    }
    //for(int i=0;i<vec.size();i++)
    //{
        //cout<<lis[i]<<" "<<lds[i]<<endl;
    //}
    return res;
}
