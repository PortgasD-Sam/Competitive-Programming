#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define FORI(n) for(ll i=0;i<n;i++)
#define MAXSIZE 300025

bool vis[MAXSIZE];
ll par[MAXSIZE];
vi graph[MAXSIZE];

ll n,x,y,c1,c2,notx,noty;

void bfs(ll s)
{
	par[s] = -1;
	queue<ll> q;
	q.push(s);
	vis[s] = 1;
	while(!q.empty())
	{
		ll front = q.front();
		q.pop();
		FORI(graph[front].size())
		{
			if(!vis[graph[front][i]])
			{
				vis[graph[front][i]] = 1;
				par[graph[front][i]] = front;
				q.push(graph[front][i]);
			}
		}
	}
}

void dfs1(ll s)
{
	vis[s] = 1;
	c1++;
	FORI(graph[s].size())
	{
		if(vis[graph[s][i]]) continue;
		if(graph[s][i]==notx) continue;
		dfs1(graph[s][i]);
	}
}

void dfs2(ll s)
{
	vis[s] = 1;
	c2++;
	FORI(graph[s].size())
	{
		if(vis[graph[s][i]]) continue;
		if(graph[s][i]==noty) continue;
		dfs2(graph[s][i]);
	}
}

int main()
{
	scanf("%lld%lld%lld",&n,&x,&y);
	FORI(n-1)
	{
		ll u,v;
		scanf("%lld%lld",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	par[x] = -1;
	bfs(x);
	vi path;
	path.push_back(y);
	ll p = par[y];
	while(p!=-1)
	{
		path.push_back(p);
		p = par[p];
	}
	reverse(path.begin(),path.end());
	notx = path[1];
	noty = path[path.size()-2];
	memset(vis,0,MAXSIZE);
	dfs1(x);
	memset(vis,0,MAXSIZE);
	dfs2(y);
	ll ans = (n * (n-1)) - (c1 * c2);
	return !printf("%lld",ans);
}