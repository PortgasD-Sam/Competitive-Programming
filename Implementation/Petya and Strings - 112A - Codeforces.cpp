#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FORI(n) for(int i=0;i<n;i++)

int main()
{
    IOS;
    string s,w;
    cin>>s>>w;
    FORI(s.size()) if(isupper(s[i])) s[i] = tolower(s[i]);
    FORI(w.size()) if(isupper(w[i])) w[i] = tolower(w[i]);
    if(s.compare(w) < 0) cout<<"-1\n";
    else if(s.compare(w) > 0) cout<<"1\n";
    else cout<<"0\n";
    return 0;
}