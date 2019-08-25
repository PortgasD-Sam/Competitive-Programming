#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAXSIZE 100024

int arr[MAXSIZE];

void init()
{
    FOR(i,0,MAXSIZE) arr[i] = i;
}

int root(int x)
{
    while(arr[x]!=x) x = arr[arr[x]];
    return x;
}

void join(int x,int y)
{
    int rx = root(x);
    int ry = root(y);
    if(rx!=ry) arr[ry] = rx;
}

int32_t main()
{
    IOS;
    init();
    int n,k;
    cin>>n>>k;
    while(k--)
    {
        int x,y;
        cin>>x>>y;
        join(x,y);
    }
    set<int> s;
    FOR(i,1,n+1) s.insert(root(arr[i]));
    cout<<s.size()<<"\n";
    return 0;
}