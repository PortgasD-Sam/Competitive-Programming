#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

#define MAXSIZE 10024
#define FORI(n) for(int i=0;i<n;i++)

vvi graph(MAXSIZE);
bool vis[MAXSIZE];
int level[MAXSIZE];

void bfs(int s,int e)
{
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		for(auto u : graph[front])
		{
			if(!vis[u])
			{
				vis[u] = true;
				level[u] = level[front] + 1;
				if(u==e)return;
				q.push(u);
			}
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		FORI(MAXSIZE) graph[i].clear();
		memset(vis,false,sizeof(vis));
		memset(level,0,sizeof(level));
		int n,m;
		scanf("%d%d",&n,&m);
		if(n==1) {printf("1\n1");continue;}
		FORI(m)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		FORI(n) sort(graph[i].begin(),graph[i].end());
		bfs(1,n);
		printf("%d\n",level[n]);
	}
	return 0;
}