#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define FORI(n) for(ll i=0;i<n;i++)
#define FORJ(n) for(ll j=0;j<n;j++)

string generate_key(bitset<5> a,bitset<5> b)
{
    string s = a.to_string() + b.to_string();
    return s;
}

int main()
{
    IOS;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,ans{};
        cin>>n;
        map<string,ll> a;
        unordered_set<string> used;
        string s;
        FORI(n)
        {
            cin>>s;
            sort(s.begin(),s.end());
            s.erase(unique(s.begin(),s.end()),s.end());
            bitset<5> b;
            FORJ(5) b[i] = 0;
            FORJ(s.size())
            {
                if(s[j]=='a') b[4] = 1;
                if(s[j]=='e') b[3] = 1;
                if(s[j]=='i') b[2] = 1;
                if(s[j]=='o') b[1] = 1;
                if(s[j]=='u') b[0] = 1;
            }
            a[b.to_string()]++;
        }
        bitset<5> all(31);
        FORI(32)
        {
            bitset<5> b1(i);
            if(!a[b1.to_string()]) continue;
            FORJ(32)
            {
                if(i==j) continue;
                bitset<5> b2(j);
                if(!a[b2.to_string()]) continue;
                if((b1|b2)==all)
                {
                    if(used.find(generate_key(b1,b2))!=used.end() || used.find(generate_key(b2,b1))!=used.end()) continue;
                    else
                    {
                        ans+=a[b1.to_string()]*a[b2.to_string()];
                        used.insert(generate_key(b1,b2));
                        used.insert(generate_key(b2,b1));
                    }
                }
            }
        }
        if(a["11111"]>1) ans+=a["11111"]*(a["11111"]-1)/2;
        cout<<ans<<endl;
    }
    return 0;
}