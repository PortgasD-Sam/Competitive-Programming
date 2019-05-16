#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MOD 1000000007
#define MAXSIZE 1024
#define FORI(k,n) for(ll i=k;i<n;i++)
#define FORJ(k,n) for(ll j=k;j<n;j++)

bool vis[MAXSIZE][MAXSIZE];
bool graph[MAXSIZE][MAXSIZE];

ll fact[1000006];
ll dx[] = {1,2,2,1,-1,-2,-2,-1};
ll dy[] = {2,1,-1,-2,-2,-1,1,2};
ll n,m,q,sum;

void pre()
{
	fact[0] = 1;
	FORI(1,1000006) fact[i] = (fact[i-1] * i)%MOD;
}

bool val(ll x,ll y)
{
	return (x>=1 && x<=n && y>=1 && y<=m);
}

void dfs(ll x,ll y)
{
	vis[x][y] = true;
	sum++;
	FORI(0,8)
	{
		ll nx = x + dx[i];
		ll ny = y + dy[i];
		if(val(nx,ny) && !vis[nx][ny] && graph[nx][ny]) dfs(nx,ny);
	}
}

int main()
{
    pre();
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		ll ans = 1;
        memset(graph,false,sizeof(graph));
        memset(vis,false,sizeof(vis));
		scanf("%lld",&q);
		FORI(0,q)
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			graph[x][y] = true;
		}
		FORI(0,n)
		{
			FORJ(0,m)
			{
				if(!vis[i][j] && graph[i][j])
				{
					sum = 0;
					dfs(i,j);
					ans = ((fact[sum] % MOD) * (ans % MOD)) % MOD;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}