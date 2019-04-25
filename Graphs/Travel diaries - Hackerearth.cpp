#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
using vi = vector<int>;
 
#define MAXSIZE 1024
#define FORI(n) for(int i=0;i<n;i++)
#define FORJ(n) for(int j=0;j<n;j++)
 
int n,m,ans;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int graph[MAXSIZE][MAXSIZE];
 
bool valid(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<m) return true;
	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	FORI(n) FORJ(m) scanf("%d",&graph[i][j]);
	queue<pi> q;
	FORI(n) FORJ(m) if(graph[i][j]==2) q.push({i,j});
	q.push({-1,-1});
	while(!q.empty())
	{
		bool f = false;
		while(q.front().first!=-1 && q.front().second!=-1)
		{
		    pi front = q.front();
			FORI(4)
			{
				int nx = front.first + dx[i];
				int ny = front.second + dy[i];
				if(valid(nx,ny) && graph[nx][ny]==1)
				{
					graph[nx][ny] = 2;
					q.push({nx,ny});
					if(!f)
					{
						f = true;
						ans++;
					}
				}
			}
			q.pop();
		}
		q.pop();
		if(!q.empty()) q.push({-1,-1});
	}
	FORI(n) FORJ(m) if(graph[i][j]==1) return !printf("%d\n",-1);
	return !printf("%d\n",ans);
}