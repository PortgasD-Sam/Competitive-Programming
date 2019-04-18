#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
using vpi = vector<pi>;

#define MAXSIZE 100024
#define FORI(n) for(int i=0;i<n;i++)

bool vis[MAXSIZE];
vpi graph[MAXSIZE];
int sum[MAXSIZE],n;

int bfs(int s)
{
	queue<int> q;
	q.push(s);
	FORI(MAXSIZE)
	{
		vis[i] = false;
		sum[i] = 0;
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
				sum[graph[front][i].first]+=sum[front] ^ graph[front][i].second;
				q.push(graph[front][i].first);
			}
		}
	}
	int c = 0;
	FORI(MAXSIZE) if(sum[i]%2==1 && (graph[i].size()==1 || graph[i].size()==1 && i==1)) c++;
	return c;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		FORI(MAXSIZE) graph[i].clear();
		int n;
		scanf("%d",&n);
		FORI(n-1)
		{
			int u,v,dst;
			scanf("%d%d%d",&u,&v,&dst);
			graph[u].push_back({v,dst});
			graph[v].push_back({u,dst});
		}
		printf("%d\n",bfs(1));
	}
	return 0;
}