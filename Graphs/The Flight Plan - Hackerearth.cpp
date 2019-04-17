#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

#define MAXSIZE 1024
#define FORI(n) for(int i=0;i<n;i++)

vvi graph(MAXSIZE);
vi from(MAXSIZE);
int n,m,t,c;
queue<int> q;
bool vis[MAXSIZE];

void bfs(int s,int e)
{
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
				from[u] = front;
				vis[u] = true;
				if(u==e) return;
				q.push(u);
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&t,&c);
	memset(vis,false,sizeof(vis));
	if(n==1) return !printf("1\n1");
	FORI(m)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int x,y;
	scanf("%d%d",&x,&y);
	vi ans;
	FORI(n) sort(graph[i].begin(),graph[i].end());
	bfs(x,y);
	ans.push_back(y);
	int s = from[y];
	while(s!=x)
	{
		ans.push_back(s);
		s = from[s];
	}
	ans.push_back(x);
	reverse(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	FORI(ans.size()) printf("%d ",ans[i]);
	return 0;
}