#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)

const int N = 1e6 + 5;

int t[2*N],n,q,a,b;
string s;

void update(int p,int x)
{
    p+=n;
    t[p]+=x;
    while(p>1)
    {
    	t[p>>1] = t[p] + t[p^1];
    	p>>=1;
    }
}

int query(int l,int r)
{
    int ans = 0;
    for(l+=n,r+=n; l<r; l>>=1,r>>=1)
    {
        if(l&1) ans+=t[l++];
        if(r&1) ans+=t[--r];
    }
    return ans;
}

int32_t main()
{
    cin>>n>>q;
    FOR(i,0,q)
    {
        cin>>s>>a>>b;
        a--;
        if(s=="find") cout<<query(a,b)<<"\n";
        if(s=="add") update(a,b);
    }
    return 0;
}