#include <bits/stdc++.h>
using namespace std;
#define FORI(n) for(int i=0;i<n;i++)

class vertex
{
    public:
        int value,i,j,original_position;
        bool operator <(const vertex &n)
        {
            if(value != n.value)
            return value > n.value;
            return j > n.j;
        }
};

int tree[30005],n;
vertex data[230005];

int prefix_query(int idx)
{
    int result = 0;
    while(idx > 0)
    {
        result+=tree[idx];
        idx-=idx & -idx;
    }
    return result;
}
void update(int idx,int val)
{
    while(idx <= n)
    {
        tree[idx]+=val;
        idx+=idx & -idx;
    }
}
int main()
{
    int m{};
    scanf("%d",&n);
    FORI(n)
    {
        scanf("%d",&data[i].value);
        data[i].i = i+1;
        data[i].j = -1;
    }
    scanf("%d",&m);
    int res[m];
    FORI(m)
    {
        scanf("%d%d%d",&data[i+n].i,&data[i+n].j,&data[i+n].value);
        data[i+n].original_position = i;
    }
    sort(data,data+n+m);
    FORI(n+m)
    {
        if(data[i].j==-1)
        update(data[i].i,1);
        else
        { 
            int result = prefix_query(data[i].j) - prefix_query(data[i].i - 1);
            res[data[i].original_position] = result;
        }
    }
    FORI(m)
    printf("%d\n",res[i]);
    return 0;
}