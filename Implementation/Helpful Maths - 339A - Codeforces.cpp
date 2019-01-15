#include <bits/stdc++.h>
using namespace std;
#define FORI(n) for(int i=0;i<n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using vi = vector<int>;

int main()
{
    IOS;
    string s;
    cin>>s;
    vi a;
    FORI(s.length()) if(isdigit(s[i])) a.push_back(s[i]-'0');
    sort(a.begin(),a.end());
    int k{};
    FORI(s.length()) (isdigit(s[i]))?cout<<a[k++]:cout<<s[i];
    return 0;
}