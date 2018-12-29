#include <bits/stdc++.h>
using namespace std;

struct vertex
{
    int sum,prefix,suffix,answer;
}t[1<<17];
int N = 1<<16;

vertex combine(vertex l ,vertex r)
{
    vertex res;
    res.sum = l.sum + r.sum;
    res.prefix = max(l.prefix,l.sum + r.prefix);
    res.suffix = max(r.suffix,r.sum + l.suffix);
    res.answer = max(max(l.answer,r.answer),l.suffix + r.prefix);
    return res;
}
vertex make_vertex(int val)
{
    vertex res;
    res.sum = val;
    res.prefix = res.suffix = res.answer = max(-1000000,val);
    return res;
}
vertex query(int i,int l,int r,int L,int R)
{
    if((l==L) && (r==R))
    return t[i];
    int M = (L+R)>>1;
    if(r<=M)
    return query(i<<1,l,r,L,M);
    else if(l>M)
    return query(i<<1|1,l,r,M+1,R);
    else
    return combine(query(i<<1,l,M,L,M),query(i<<1|1,M+1,r,M+1,R));
}
int main()
{
    int temp{},n{};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        t[N+i] = make_vertex(temp);
    }
    for(int i=N-1;i>0;i--)
    t[i] = combine(t[i<<1],t[i<<1|1]);
    scanf("%d",&temp);
    int x{},y{};
    while(temp--)
    {
        scanf("%d%d",&x,&y);
        x--;
        y--;
        printf("%d\n",query(1,x,y,0,N-1).answer);
        
    }
    return 0;
}