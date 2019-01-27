#include <bits/stdc++.h>
using namespace std;
#define FORI(n) for(int i=0;i<n;i++)

int main()
{
    set<int> s;
    s.insert(0);
    int n{},k{},tm{};
    scanf("%d%d",&n,&k);
    FORI(n) {scanf("%d",&tm);s.insert(tm);}
    auto it = s.begin();
    while(k--)
    {
        if(next(it)==s.end())
        printf("%d\n",0);
        else
        {
            printf("%d\n",*next(it)-*it);
            it = next(it);
        }
    }
    return 0;
}