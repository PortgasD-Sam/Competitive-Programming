#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007

int n,q,a[100024],l,r,tree[400024][45],po[100024];

void create()
{
    po[0] = 1;
    FOR(i,1,100005) po[i] = (2*po[i-1]) % MOD;
    FOR(i,0,43)
    {
        FOR(j,1,n+1)
        {
            tree[j][i] = tree[j-1][i];
            if(a[j] & (1LL<<i)) tree[j][i]++;
        }
    }
}

int32_t main()
{
    IOS;
    cin>>n;
    FOR(i,1,n+1) cin>>a[i];
    create();
    int x;
    cin>>q>>x;
    while(q--)
    {
        cin>>l>>r;
        int c1 = 0,c0 = 0,ans = 0,ans1 = 0;
        FOR(i,0,43)
        {
            c1 = tree[r][i] - tree[l-1][i];
            c0 = r - l + 1 - c1;
            ans = c1 * (c0 * (c0 - 1))/2;
            ans%=MOD;
            ans+= (c1 * (c1 - 1) * (c1 - 2))/6;
            ans%=MOD;
            ans*=po[i];
            ans%=MOD;
            ans1+=ans;
            ans1%=MOD;
        }
        cout<<ans1<<"\n";
    }
    return 0;
}