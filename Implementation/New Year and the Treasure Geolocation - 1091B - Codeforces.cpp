#include <bits/stdc++.h>
using namespace std;
#define FORI(n) for(ll i=0;i<n;i++)
using ll = long long;
using vpl = vector<pair<ll,ll>>;
using pl = pair<ll,ll>;

int main()
{
    ll n{};
    scanf("%lld",&n);
    vpl a(n),b(n);
    FORI(n) scanf("%lld%lld",&a[i].first,&a[i].second);
    FORI(n) scanf("%lld%lld",&b[i].first,&b[i].second);
    pl coordinates = {0,0};
    FORI(n) {coordinates.first+=a[i].first+b[i].first;coordinates.second+=a[i].second+b[i].second;}
    return !printf("%lld %lld\n",(coordinates.first/n),(coordinates.second/n));
}