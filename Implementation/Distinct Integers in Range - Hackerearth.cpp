#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int a[100001],b[100001];
bitset<5001> tree1[400001],tree2[400001];

void build(int node,int i,int j)
{
    if(i>j) return;
    if(i==j)
    {
        tree1[node].set(a[i]);
        tree2[node].set(b[i]);
        return;
    }
    int mid = (i+j)/2;
    build(2*node,i,mid);
    build(2*node+1,mid+1,j);
    tree1[node] = tree1[2*node] | tree1[2*node + 1];
    tree2[node] = tree2[2*node] | tree2[2*node + 1];
}

bitset<5001> query1(int node,int i,int j,int l,int r)
{
    if(i>j || i>r || j<l) return 0;
    if(i>=l && j<=r) return tree1[node];
    int mid = (i+j)/2;
    return query1(2*node,i,mid,l,r) | query1(2*node + 1,mid + 1,j,l,r);
}

bitset<5001> query2(int node,int i,int j,int l,int r)
{
    if(i>j || i>r || j<l) return 0;
    if(i>=l && j<=r) return tree2[node];
    int mid = (i+j)/2;
    return query2(2*node,i,mid,l,r) | query2(2*node + 1,mid + 1,j,l,r);
}

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    FOR(i,1,n+1) cin>>a[i];
    FOR(i,1,n+1) cin>>b[i];
    build(1,1,n);
    int q,a,b,c,d;
    cin>>q;
    while(q--)
    {
        cin>>a>>b>>c>>d;
        cout<<(query1(1,1,n,a,b) | query2(1,1,n,c,d)).count()<<"\n";
    }
    return 0;
}