#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main()
{
    IOS;
    int n,x,c = 0;
    cin>>n>>x;
    int a[n];
    FOR(i,0,n) cin>>a[i];
    FOR(i,0,n)
    {
        if(x==0) break;
        x-=a[i];
        x = max(0LL,x);
        c++;
    }
    cout<<c<<"\n";
    return 0;
}