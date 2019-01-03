#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FORI(n) for(int i=0;i<n;i++)
#define FORJ(n) for(int j=0;j<n;j++)

int main()
{
    IOS;
    map<int,int> m;
    int n{};
    cin>>n;
    vi a(n);
    FORI(n)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    int c{};
    FORI(n)
    {
        bool status = false;
        FORJ(31)
        {
            int x = (1<<j) - a[i];
            if(m.count(x)>0 && (m[x]>1 || (m[x]==1 && x!=a[i])))
            status = true;
        }
        if(!status)
        c++;
    }
    cout<<c<<endl;
    return 0;
}