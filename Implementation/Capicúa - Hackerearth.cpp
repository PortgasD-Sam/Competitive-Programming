#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

string to_s(int x)
{
  stringstream ss;
  ss << x;
  return ss.str();
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        bool f = true;
        int n;
        cin>>n;
        string s = to_s(n);
        FOR(i,0,s.size()/2)
        {
            if(s[i]!=s[s.size() - i - 1])
            {
                f = false;
                break;
            }
        }
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}