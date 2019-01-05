#include <bits/stdc++.h>
using namespace std;
#define FORI(n) for(int i=0;i<n;i++)
#define FORJ(n) for(int j=0;j<n;j++)

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
const int N = 1005;
char board[N][N];
bool visited[N][N][3][4];
int n{},m{};

bool is_valid_move(int x,int y,int turns,int direction)
{
    if((x>=0 && x<n) && (y>=0 && y<m) && board[x][y]!='*' && !visited[x][y][turns][direction]) return true;
    else return false;
}

void dfs(int x,int y,int turns,int direction)
{
    if(turns > 2)
    return;
    if(board[x][y] == 'T')
    {
        printf("YES\n");
        exit(0);
    }
    FORI(4)
    {
        int nx = dx[i]+x;
        int ny = dy[i]+y;
        if(is_valid_move(nx,ny,turns,i))
        {
            visited[nx][ny][turns][i] = true;
            dfs(nx,ny,turns+(i!=direction),i);
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    int sx{},sy{};
    FORI(n) FORJ(m) {scanf(" %c",&board[i][j]);if(board[i][j]=='S'){sx = i;sy = j;}}
    FORI(4){memset(visited,false,sizeof(visited));dfs(sx,sy,0,i);}
    return !printf("NO\n");
}