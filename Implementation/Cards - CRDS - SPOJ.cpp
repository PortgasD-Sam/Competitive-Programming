#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000007

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    while(n--)
    {
        int k,ans = 0;
        cin>>k;
        ans = ((2LL * (k * (k + 1)) / 2) % MOD + ((k * (k - 1)) / 2) % MOD) % MOD;
        cout<<ans<<"\n";
    }
    return 0;
}