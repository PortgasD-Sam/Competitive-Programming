#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;


int main()
{
    int n{},t{},count1{},count2{1};
    scanf("%d",&n);
    vi sequence,required;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        sequence.push_back(t);
        if(t==1)
        count1++;
    }
    sequence.push_back(1);
    for(int i=1;i<=n;i++)
    {
        count2++;
        if(sequence[i]==1)
        {
            required.push_back(count2 - 1);
            count2 = 1;
        }
    }
    printf("%d\n",count1);
    for(int i=0;i<required.size();i++)
    printf("%d ",required[i]);
    return 0;
}