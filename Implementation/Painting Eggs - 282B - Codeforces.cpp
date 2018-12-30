#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    IOS;
    string s;
    int a{},g{},n{},p{},q{};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p>>q;
        if((a+p-g)>500)
        {
            g+=q;
            s+="G";
        }
        else
        {
            a+=p;
            s+="A";
        }
        if(abs(a-g)>500)
        {
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<s<<endl;
    return 0;
}