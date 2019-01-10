#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FORI(n) for(int i=0;i<n;i++)
#define endl "\n"

int main()
{
    IOS;
    string s;
    cin>>s;
    s+="H";
    int n = s.length(),c{1},mx{INT_MIN};
    FORI(n-1)
    {
        if(s[i] == s[i+1])
        c++;
        else
        {
            mx = max(mx,c);
            c = 1;
        }
    }
    if(mx>=7)
    cout<<"YES\n";
    else
    cout<<"NO\n";
    return 0;
}