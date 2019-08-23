#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main()
{
    IOS;
    int n,k;
    cin>>n>>k;
    vector<int> a;
    FOR(i,0,n)
    {
        int t;
        cin>>t;
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    bool f = false;
    for(int l=0,r=a.size()-1;l<r;)
    {
        int sum = a[l] + a[r];
        if(sum<k) l++;
        else if(sum>k) r--;
        else
        {
            f = true;
            break;
        }
    }
    if(f) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}