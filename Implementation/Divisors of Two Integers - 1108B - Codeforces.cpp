#include <bits/stdc++.h>
using namespace std;

#define FORI(s,n) for(int i=s;i<=n;i++)
#define endl "\n"

int main()
{
    int n{},x{},y{},tm{};
    scanf("%d",&n);
    multiset<int> a;
    FORI(1,n) {scanf("%d",&tm);a.insert(tm);}
    x = *a.rbegin();
    FORI(1,x) {if(x%i == 0) a.erase(a.find(i));}
    y = *a.rbegin();
    return !printf("%d %d",x,y);
}