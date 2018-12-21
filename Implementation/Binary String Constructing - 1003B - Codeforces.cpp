#include <bits/stdc++.h>
using namespace std;
#define FORI(n) for(int i=1;i<=n;i++)
#define endl "\n"

int main()
{
    int a{},b{},x{},n{};
    cin>>a>>b>>x;
    string s;
    n = x/2;
    if(x%2)
    {
        if(a>b)
        {
            s = "01";
            FORI(n)cout<<s;
            FORI(a-n)cout<<"0";
            FORI(b-n)cout<<"1";
            cout<<endl;
        }
        else
        {
            s = "10";
            FORI(n)cout<<s;
            FORI(b-n)cout<<"1";
            FORI(a-n)cout<<"0";
            cout<<endl;
        }
    }
    else
    {
        if(a>b)
        {
            s = "01";
            FORI(n)cout<<s;
            FORI(b-n)cout<<"1";
            FORI(a-n)cout<<"0";
            cout<<endl;
        }
        else
        {
            s = "10";
            FORI(n)cout<<s;
            FORI(a-n)cout<<"0";
            FORI(b-n)cout<<"1";
            cout<<endl;
        }        
    }
    return 0;
}