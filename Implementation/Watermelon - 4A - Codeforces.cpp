#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w{};
    cin>>w;
    bool status{false};
    for(int i=2;i<w;i+=2)
    {
        if((w-i)%2==0)
        {
            status =true;
            break;
        }
    }
    if(status)
    cout<<"YES\n";
    else
    cout<<"NO\n";
    return 0;
}