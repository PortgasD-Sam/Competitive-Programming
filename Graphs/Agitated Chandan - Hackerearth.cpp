#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
using vpi = vector<pi>;

#define MAXSIZE 100024
#define FORI(n) for(int i=0;i<n;i++)

vpi graph[MAXSIZE];
bool vis[MAXSIZE];
int dst[MAXSIZE],n;

int bfs(int s)
{
	queue<int> q;
	q.push(s);
	FORI(MAXSIZE)
	{
		vis[i] = false;
		dst[i] = 0;
	}
	vis[s] = true;
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		FORI(graph[front].size())
		{
			if(!vis[graph[front][i].first])
			{
				vis[graph[front][i].first] = true;
				dst[graph[front][i].first]+= dst[front] + graph[front][i].second;
				q.push(graph[front][i].first);
			}
		}
	}
	return int(max_element(dst+1,dst+n+1) - dst);
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		FORI(MAXSIZE) graph[i].clear();
		FORI(n-1)
		{
			int u,v,dst;
			scanf("%d%d%d",&u,&v,&dst);
			graph[u].push_back({v,dst});
			graph[v].push_back({u,dst});
		}
		int ans = bfs(1);
		ans = bfs(ans);
		ans = dst[ans];
		int price = 0;
		if(ans>100) price = 100;
		if(ans>1000) price = 1000;
		if(ans>10000) price = 10000;
		printf("%d %d\n",price,ans);
	}
	return 0;
}