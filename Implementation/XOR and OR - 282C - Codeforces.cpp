#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FORI(n) for(int i=0;i<n;i++)

int main()
{
    IOS;
    string a,b;
    cin>>a>>b;
    int ca{},cb{};
    if(a.length()!=b.length())
    {
        cout<<"NO\n";
        return 0;
    }
    FORI(a.length())
    {
        if(a[i]=='1')
        ca++;
        if(b[i]=='1')
        cb++;
    }
    if((ca>0)^(cb>0))
    cout<<"NO\n";
    else
    cout<<"YES\n";
    return 0;
}