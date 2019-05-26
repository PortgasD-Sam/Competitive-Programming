#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FORI(n) for(ll i=0;i<n;i++)

int main()
{
	ll n,k,mn = INT_MAX;
	scanf("%lld%lld",&n,&k);
	ll a[n],b[n];
	FORI(n) scanf("%lld",&a[i]);
	FORI(n)
	{
		mn = min(a[i],mn);
		b[i] = a[i] - mn;
	}
	sort(b,b+n);
	ll ans = k * b[n-1];
	printf("%lld\n",ans);
	return 0;
}