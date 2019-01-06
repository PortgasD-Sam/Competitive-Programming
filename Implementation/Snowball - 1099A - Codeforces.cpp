#include <bits/stdc++.h>
using namespace std;
#define FORI(n) for(int i=n;i>0;i--)

struct path
{
    int height,weight;
    path()
    {
        weight = 0;
    }
};

int main()
{
    int w{},h{},u{},d{};
    scanf("%d%d",&w,&h);
    vector<path> p(h+1);
    FORI(h) {p[i].height = i;p[i].weight = p[i].height;}
    FORI(2) {scanf("%d%d",&u,&d);p[d].weight+= -u;}
    FORI(h){w+=p[i].weight;if(w<0)w = 0;}
    return !printf("%d",w);
}