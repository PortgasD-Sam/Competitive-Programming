#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define endl "\n"
#define FORI(n) for(ll i=0;i<n;i++)

int main()
{
    ll n{},k{},m{},temp{};
    cin>>n>>k;
    vl a(n);
    FORI(n)
    {
        cin>>a[i];
        if(!i)m = a[i];
        else m = min(m,a[i]);
    }
    ll c{};
    FORI(n)
    {
        if((a[i]-m)%k==0)c+=(a[i]-m)/k;
        else
        {
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<c<<endl;
    return 0;
}