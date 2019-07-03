#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1000005;

struct T
{
	ll v,l,r,t,p;
	T()
	{
		v = l = r = t = p = 0;
	}
	bool operator <(T &a)
	{
		if(v!=a.v) return v > a.v;
		return t > a.t;
	}
};

T a[N];
ll t[2*N],ans[N],n,q;

void modify(ll p)
{
	for(t[p+=n]=1;p > 1;p>>=1) t[p>>1] = t[p] + t[p^1];
}

ll query(ll l,ll r)
{
	ll res = 0;
	for(l+=n,r+=n;l < r;l>>=1,r>>=1)
	{
		if(l&1) res+=t[l++];
		if(r&1) res+=t[--r];
	}
	return res;
}

int main()
{
	scanf("%lld",&n);
	for(ll i=0;i<n;i++)
	{
		scanf("%lld",&a[i].v);
		a[i].p = i;
	}
	scanf("%lld",&q);
	ll k = q;
	for(ll i=n;q-->0;i++)
	{
		scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].v);
		a[i].t = 1;
		a[i].p = i-n;
	}
	sort(a,a+n+k);
	for(ll i=0;i<n+k;i++)
	{
		if(a[i].t==0) modify(a[i].p);
		else ans[a[i].p]=query(a[i].l - 1,a[i].r);
	}
	for(ll i=0;i<k;i++) printf("%lld\n",ans[i]);
	return 0;
}