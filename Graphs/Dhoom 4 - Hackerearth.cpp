#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MOD 100000
#define MAXSIZE 100024
#define FORI(n) for(ll i=0;i<n;i++)

ll vis[MAXSIZE];

int main()
{
	ll key,lock,n;
	scanf("%lld%lld%lld",&key,&lock,&n);
	ll a[n];
	FORI(n) scanf("%lld",&a[i]);
	queue<ll> q;
	memset(vis,-1,sizeof(vis));
	q.push(key);
	vis[key] = 0;
	while(!q.empty())
	{
		ll front = q.front();
		q.pop();
		if(front==lock) break;
		FORI(n)
		{
			if(vis[(front*a[i])%MOD]==-1)
			{
				vis[(front*a[i])%MOD] = vis[front] + 1;
				q.push((front*a[i])%MOD);
			}
		}
	}
	return !printf("%lld\n",vis[lock]);
}