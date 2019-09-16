#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int rev(int x)
{
    int r = 0;
    for(int i=x;i>0;i/=10) r = r*10 + (i%10);
    return r;
}

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        int s = rev(a) + rev(b);
        s = rev(s);
        cout<<s<<"\n";
    }
    return 0;
}