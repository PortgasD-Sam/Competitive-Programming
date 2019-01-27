#include <bits/stdc++.h>
using namespace std;
#define FORI(s,n) for(int i=s;i<=n;i++)
#define FORJ(s,n) for(int j=s;j<=n;j++)

int main()
{
    int x{},a{},b{};
    bool status = false;
    scanf("%d",&x);
    FORI(1,x) FORJ(1,x) {if((i%j==0)&&((i*j)>x)&&((i/j)<x)){a = i;b = j;status = true;}}
    if(status) printf("%d %d\n",a,b);
    else printf("%d",-1);
    return 0;
}