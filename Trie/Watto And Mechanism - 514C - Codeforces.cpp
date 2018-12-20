#include <bits/stdc++.h>
using namespace std;

struct trie
{
    int occurance;
    trie *child[3];
    trie()
    {
        occurance = 0;
        for(int i=0;i<3;i++)
        child[i] = nullptr;
    }
};
trie *insert(trie *t,string const &s,int idx)
{
    if(idx == s.length())
    {
        t->occurance++;
        return t;
    }
    if(t->child[s[idx]-'a'] == nullptr)
    t->child[s[idx]-'a'] = new trie();
    t->child[s[idx]-'a'] = insert(t->child[s[idx]-'a'],s,idx+1);
    return t;
}
bool find(trie *t,string const &s,int idx,int count)
{
    if(idx == s.length())
    {
        if(count == 1 && t->occurance >0)return true;
        return false;
    }
    if(!count)
    {
        for(int i=0;i<3;i++)
        {
            if(t->child[i]!=nullptr && i!=s[idx]-'a')
            if(find(t->child[i],s,idx+1,1))return true;
        }
    }
    if(t->child[s[idx]-'a']==nullptr)return false;
    return find(t->child[s[idx]-'a'],s,idx+1,count);
}
int main()
{
    int n{},m{};
    cin>>n>>m;
    string s;
    trie *t = new trie();
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        t = insert(t,s,0);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>s;
        find(t,s,0,0)?cout<<"YES\n":cout<<"NO\n";
    }
    return 0;
}
