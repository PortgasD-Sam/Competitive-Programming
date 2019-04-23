#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

#define FORI(n) for(int i=0;i<n;i++)

int main()
{
	int n,e;
	scanf("%d%d",&n,&e);
	vvi graph(n);
	bool vis[n];
	int dst[n];
	FORI(e)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		memset(vis,false,sizeof(vis));
		memset(dst,0,sizeof(dst));
		queue<int> q;
		q.push(s);
		vis[s] = true;
		while(!q.empty())
		{
			int front = q.front();
			q.pop();
			FORI(graph[front].size())
			{
				if(!vis[graph[front][i]])
				{
					vis[graph[front][i]] = true;
					dst[graph[front][i]] = dst[front] + 1;
					q.push(graph[front][i]);
				}
			}
		}
		int ans = 0;
		FORI(n) if(dst[i]==t) ans++;
		printf("%d\n",ans);
	}
	return 0;
}