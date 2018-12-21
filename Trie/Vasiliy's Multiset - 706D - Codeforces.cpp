#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

struct trie
{
    trie *child[2];
    int count,num;
    trie()
    {
        child[0]=child[1]=nullptr;
        count=num=0;
    }
};

trie *root;
void insert(int x)
{
    bitset<32> b(x);
    trie *current = root;
    for(int i=31,num;i>=0;i--)
    {
        num = b[i];
        if(current->child[num] == nullptr)
        current->child[num] = new trie();
        current = current->child[num];
        ++current->count;
    }
    current->num = x;
}
void remove(int x)
{
    bitset<32> b(x);
    trie *current = root;
    for(int i=31;i>=0;i--)
    {
        current = current->child[b[i]];
        --current->count;
    }
}
int find(int x)
{
    bitset<32> b(x);
    trie *current = root;
    for(int i=31,num;i>=0 && current!=nullptr;i--)
    {
        num = b[i];
        if(num == 0)
        {
            if(current->child[1]!=nullptr && current->child[1]->count>0)
            current = current->child[1];
            else
            current = current->child[0];
        }
        else
        {
            if(current->child[0]!=nullptr && current->child[0]->count>0)
            current = current->child[0];
            else
            current = current->child[1];
        }
    }
    if(current == nullptr)
    return x;
    return max(x^current->num,x);
}
int main()
{
    int q{},n{};char c;
    root = new trie();
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>c>>n;
        if(c == '+')
        insert(n);
        else if(c == '-')
        remove(n);
        else
        cout<<find(n)<<endl;
    }
    return 0;
}