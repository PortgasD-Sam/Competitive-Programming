#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int rev(int x)
{
    stack<int> s;
    while(x)
    {
        s.push(x%2);
        x/=2;
    }
    int i = 0,r = 0;
    while(!s.empty())
    {
        r += (s.top()<<(i++));
        s.pop();
    }
    return r;
}

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        if(k%2==0) cout<<rev(k)<<"\n";
        else cout<<k<<"\n";
    }
    return 0;
}