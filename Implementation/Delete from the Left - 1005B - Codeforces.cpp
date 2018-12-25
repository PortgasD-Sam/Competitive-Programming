#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    int c{},m{(int)s.length()-1},n{(int)t.length()-1};
    for(int i=m;i>=0;i--)
    {
        if(s[i]==t[n--])
        c++;
        else
        break;
    }
    cout<<s.length()+t.length()-2*c<<endl;
    return 0;
}