#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int sequence[N], bitset_available[35], bitset_required[35];

bool check()
{
    for(int i=0;i<35;i++)
    {
        if(bitset_required[i] != 0)
        return false;
    }
    return true;
}

int main()
{
    int n{},q{},t{};
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
    {
        scanf("%d",sequence+i);
        bitset<32> bs(sequence[i]);
        for(int i=0;i<32;i++)
        if(bs[i]==1)
        bitset_available[i]++;
    }
    while(q--)
    {
        scanf("%d",&t);
        int count{};
        bitset<32> bs(t);
        memset(bitset_required,0,sizeof bitset_required);
        for(int i=0;i<32;i++)
        bitset_required[i] = bs[i];
        for(int i=31;i>=0;i--)
        {
            if(i>0 && bitset_required[i]!=0 && bitset_available[i]==0)
            {
                bitset_required[i-1]+=bitset_required[i]*2;
                bitset_required[i]=0;
            }
            else if(i>0 && bitset_required[i]!=0 && bitset_available[i]<bitset_required[i])
            {
                bitset_required[i-1]+=(bitset_required[i] - bitset_available[i])*2;
                bitset_required[i]=0;
                count+=bitset_available[i];
            }
            else if(bitset_required[i]!=0 && bitset_available[i]>=bitset_required[i])
            {
                count+=bitset_required[i];
                bitset_required[i]=0;
            }
        }
        if(check())
        printf("%d\n",count);
        else
        printf("-1\n");
    }
    return 0;
}