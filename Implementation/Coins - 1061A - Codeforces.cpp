#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    if (s%n==0) printf("%d",s/n);
    else printf("%d\n",(s/n)+1);
    return 0;
}