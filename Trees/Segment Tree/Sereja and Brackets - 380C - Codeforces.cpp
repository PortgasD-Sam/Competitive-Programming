#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

const int N = 1e6 + 5;
int n;
struct vertex
{
    int length,open,close;
    vertex()
    {
        length = open = close = 0;
    }
};
vertex t[2*N];

void build()
{
    for(int i=n-1;i>0;i--)
    {
        int temp = 2*min(t[i<<1].open,t[i<<1|1].close);
        t[i].length = t[i<<1].length + t[i<<1|1].length + temp;
        t[i].open = t[i<<1].open + t[i<<1|1].open - temp/2;
        t[i].close = t[i<<1].close + t[i<<1|1].close - temp/2;
    }
}

int query(int l,int r)
{
    l--;
    int result{},a{},b{},temp{};
    for(l+= n,r+= n;l < r;l>>=1,r>>=1)
    {
        if(l&1)
        {
            temp = 2*min(t[l].close,a);
            a-= temp/2;
            a+= t[l].open;
            result+= t[l].length + temp;
            l++;
        }
        if(r&1)
        {
            r--;
            temp = 2*min(t[r].open,b);
            b-= temp/2;
            b+=t[r].close;
            result+= t[r].length + temp;
        }
    }
    return (result+2*min(a,b));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    n = s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i] == '(')
        t[i+n].open = 1;
        else
        t[i+n].close = 1;
    }
    int m{},l{},r{};
    cin>>m;
    build();
    while(m--)
    {
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
    return 0;
}
