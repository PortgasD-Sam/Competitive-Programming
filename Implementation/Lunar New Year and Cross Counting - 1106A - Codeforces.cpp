#include <bits/stdc++.h>
using namespace std;
#define FORI(n) for(int i=0;i<n;i++)
#define FORJ(n) for(int j=0;j<n;j++)

int n;

bool is_valid(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<n) return true;
    else return false;
}

int main()
{
    int c{};
    scanf("%d",&n);
    char a[n][n];
    FORI(n) FORJ(n) scanf(" %c",&a[i][j]);
    FORI(n)
    {
        FORJ(n)
        {
            if(a[i][j] == 'X')
            {
                if(is_valid(i-1,j-1) && a[i-1][j-1] == 'X' && is_valid(i-1,j+1) && a[i-1][j+1] == 'X' && is_valid(i+1,j-1) && a[i+1][j-1] == 'X' && is_valid(i+1,j+1) && a[i+1][j+1] == 'X')
                c++;
            }
        }
    }
    return !printf("%d\n",c);
}