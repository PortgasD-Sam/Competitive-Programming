#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FORI(n) for(int i=0;i<n;i++)

int main()
{
    IOS;
    string s;
    cin>>s;
    map<char,bool> m;
    FORI(s.size()) if(!m[s[i]]) m[s[i]] = true;
    (m.size()%2)?cout<<"IGNORE HIM!\n":cout<<"CHAT WITH HER!\n";
    return 0;
}