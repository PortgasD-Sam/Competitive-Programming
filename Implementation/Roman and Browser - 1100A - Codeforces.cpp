#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define FORI(s,n) for(int i=s;i<=n;i++)

int main()
{
    int n{},k{},e{},s{},mx{INT_MIN};
    scanf("%d%d",&n,&k);
    vi type(n+1),closed;
    FORI(1,n) scanf("%d",&type[i]);
    FORI(1,n)
    {
        int j{};
        while(true)
        {
            if((i+j*k)>=1) closed.push_back(i+(j--)*k);
            else break;
        }
        j = 1;
        while(true)
        {
            if((i+j*k)<=n) closed.push_back(i+(j++)*k);
            else break;
        }
        sort(closed.begin(),closed.end());
        FORI(1,n)
        {
            if(count(closed.begin(),closed.end(),i)==0)
            {
                if(type[i]==1) ++e;
                else ++s;
            }
        }
        mx = max(mx,abs(e-s));
        e = s = 0;
        closed.clear();
    }
    return !printf("%d\n",mx);
}