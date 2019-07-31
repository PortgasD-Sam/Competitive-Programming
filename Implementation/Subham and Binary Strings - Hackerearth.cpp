#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans = 0;
        FORI(n) if(s[i]=='0') ans++;
        cout<<ans<<"\n";
    }
    return 0;
}