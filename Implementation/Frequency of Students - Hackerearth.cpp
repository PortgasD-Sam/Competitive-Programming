#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main()
{
    IOS;
    map<string,int> m;
    int t;
    cin>>t;
    vector<string> a;
    while(t--)
    {
        string s;
        cin>>s;
        m[s]++;
        a.push_back(s);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    FOR(i,0,a.size()) cout<<a[i]<<" "<<m[a[i]]<<"\n";
    return 0;
}