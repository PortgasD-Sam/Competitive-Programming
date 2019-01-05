#include <bits/stdc++.h>
using namespace std;

int main()
{
    int y{},b{},r{},m{1},n{2},o{3};
    scanf("%d%d%d",&y,&b,&r);
    while(true)
    {
        if((m+1)>y || (n+1)>b || (o+1)>r)
        return !printf("%d\n",(m+n+o));
        else
        m++,n++,o++;
    }
}