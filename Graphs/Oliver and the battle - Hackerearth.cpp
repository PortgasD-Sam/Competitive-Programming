#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
using vi = vector<int>;

#define MAXSIZE 1024
#define FORI(n) for(int i=0;i<n;i++)
#define FORJ(n) for(int j=0;j<n;j++)
#define FORK(n) for(int k=0;k<n;k++)

int n,m;
int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};
int graph[MAXSIZE][MAXSIZE];
vi countlist;

bool valid(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<m) return true;
	return false;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		FORI(MAXSIZE) FORJ(MAXSIZE) graph[i][j] = 0;
		FORI(n) FORJ(m) scanf("%d",&graph[i][j]);
		countlist.clear();
		FORI(n)
		{
			FORJ(m)
			{
				if(graph[i][j]==1)
				{
					queue<pi> q;
					q.push({i,j});
					graph[i][j] = 0;
					int c = 1;
					while(!q.empty())
					{
						pi front = q.front();
						q.pop();
						FORK(8)
						{
							int nx = front.first + dx[k];
							int ny = front.second + dy[k];
							if(valid(nx,ny) && graph[nx][ny]==1)
							{
								q.push({nx,ny});
								graph[nx][ny] = 0;
								c++;
							}
						}
					}
					countlist.push_back(c);
				}
			}
		}
		sort(countlist.begin(),countlist.end(),greater<int>());
		if(countlist.size()==0)
		{
			printf("%d %d\n",0,0);
			continue;
		}
		int x = countlist.size();
		int y = countlist[0];
		printf("%d %d\n",x,y);
	}
	return 0;
}