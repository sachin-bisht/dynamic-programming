#include<iostream>
#include<map>
using namespace std;

map <long long,long long> mapp;
long long rec(long long);

int main()
{
    mapp.emplace(0,0);
    long long n;
    n=3;
    while(cin>>n)
    {
        cout<<rec(n)<<endl;
    }
}

long long rec(long long n)
{
    //cout<<"!!"<<n<<endl;
    /*if(n<=0){
        cout<<0<<endl;
        return 0;
    }*/
    if(mapp.find(n)!=mapp.end()){
        //cout<<mapp[n]<<"$$"<<endl;
        return mapp[n];
    }

    else{
        long long sum=max(n,rec(n/2)+rec(n/3)+rec(n/4));
        mapp.emplace(n,sum);
        //cout<<n<<" "<<sum<<endl;
        return sum;
    }
}
