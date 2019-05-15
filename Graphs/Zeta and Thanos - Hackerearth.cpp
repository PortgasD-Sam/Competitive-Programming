#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;

#define FORI(n) for(int i=0;i<n;i++)
#define FORJ(n) for(int j=0;j<n;j++)
#define MAXSIZE 1024

int graph[MAXSIZE][MAXSIZE];
int dst[MAXSIZE][MAXSIZE];
int sum[MAXSIZE][MAXSIZE];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int n,m,q,x,y,xi,yi;

bool val(int x,int y)
{
	return (x>=1 && x<=n && y>=1 && y<=m && graph[x][y]!=-2);
}

void bfs()
{
	pi s = {x,y};
	queue<pi> q;
	FORI(n) FORJ(m) dst[i+1][j+1] = INT_MAX;
	memset(sum,-1,sizeof(sum));
	q.push(s);
	dst[s.first][s.second] = 0;
	sum[s.first][s.second] = graph[s.first][s.second];
	while(!q.empty())
	{
		pi front = q.front();
		q.pop();
		FORI(4)
		{
			int nx = front.first + dx[i];
			int ny = front.second + dy[i];
			if(val(nx,ny) && dst[nx][ny]>=dst[front.first][front.second]+1 && sum[nx][ny]<sum[front.first][front.second]+graph[nx][ny])
			{
				dst[nx][ny] = dst[front.first][front.second] + 1;
				sum[nx][ny] = sum[front.first][front.second] + graph[nx][ny];
				q.push({nx,ny});
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	FORI(n)
	{
		FORJ(m)
		{
			char c;
			scanf(" %c",&c);
			if(c!='*') graph[i+1][j+1] = c - '0';
			else graph[i+1][j+1] = -2;
		}
	}
	scanf("%d%d%d",&x,&y,&q);
	bfs();
	while(q--)
	{
		scanf("%d%d",&xi,&yi);
		if(graph[xi][yi] == -2) printf("%d %d\n",-1,-1);
		else if(dst[xi][yi] == INT_MAX) printf("%d %d\n",-1,-1);
		else printf("%d %d\n",dst[xi][yi],sum[xi][yi]);
	}
	return 0;
}