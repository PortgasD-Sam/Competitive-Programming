#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
 
#define MAXSIZE 1024
#define FORI(n) for(int i=0;i<n;i++)
 
vvi graph(MAXSIZE);
int n,k;
 
int dfs(int s,int e)
{
	vi a;
	for(auto u : graph[s])
	if(u!=e) a.emplace_back(dfs(u,s));
	if(a.size()<k) return 1;
	sort(a.begin(),a.end(),greater<int>());
	int sum = 1;
	FORI(k) sum+=a[i];
	return sum;
}
 
int main()
{
	int t,c=1;
	scanf("%d",&t);
	while(t--)
	{
		FORI(MAXSIZE) graph[i].clear();
		scanf("%d%d",&n,&k);
		FORI(n-1)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			graph[u].emplace_back(v);
			graph[v].emplace_back(u);
		}
		printf("Case %d: %d\n",c++,dfs(1,-1));
	}
	return 0;
}