#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define endl "\n";

class BIT
{
   public:
    BIT(vi sequence)
    {
        modified_sequence = vi(sequence.size()+1,0);
        for(int i=0;i<sequence.size();i++)
        modified_sequence[i+1] = sequence[i];
        for(int i=1;i<modified_sequence.size();i++)
        {
            int idx = i + (i & -i);
            if(idx < modified_sequence.size())
            modified_sequence[idx]+=modified_sequence[i];
        }
    }
    int prefix_query(int idx)
    {
        int result{};
        for(++idx;idx>0;idx-=idx & -idx)
        result+=modified_sequence[idx];
        return result;
    }
    int range_query(int from_idx,int to_idx)
    {
        if(from_idx == 0)
        return prefix_query(to_idx);
        else
        return prefix_query(to_idx)-prefix_query(from_idx-1);
    }
  private: 
    vi modified_sequence;
};

int main()
{
    int n{},k{},t{};
    double average{},max_average{};
    cin>>n>>k;
    vi sequence;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        sequence.push_back(t);
    }
    BIT bit(sequence);
    while(k<=n)
    {
        for(int i=0;i+k<=n;i++)
        {
            if(i+k<=n)
            average = (double)bit.range_query(i,i+k-1)/(double)(k);
            max_average = max(max_average,average);
        }
        k++;
    }
    cout<<fixed<<setprecision(15)<<max_average<<endl;
    return 0;
}