#include <bits/stdc++.h>
using namespace std;
int main()
{
    size_t t{};
    cin>>t;
    while(t--)
    {
        string s{};
        cin>>s;
        int len =s.length();
        if(len<=10)
        cout<<s<<endl;
        else
        cout<<s.at(0)<<len-2<<s.at(len-1)<<endl;
        }
    return 0;
}