#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FORI(s,n) for(i=s;i<=n;i++)
#define FORJ(s,n) for(j=s;j<=n;j++)
#define endl "\n"

int main()
{
    IOS;
    int q{},l1{},r1{},l2{},r2{},i{},j{};
    cin>>q;
    while(q--)
    {
        bool status = false;
        cin>>l1>>r1>>l2>>r2;
        FORI(l1,r1)
        {
            FORJ(l2,r2) if(i!=j) {status = true;break;}
            if(status) {cout<<i<<" "<<j<<endl;status = false;break;}
        }
    }
    return 0;
}