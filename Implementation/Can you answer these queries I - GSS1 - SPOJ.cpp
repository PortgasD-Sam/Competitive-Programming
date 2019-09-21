#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node
{
    int l,r,s,b;
    node()
    {
        l = 0,r = 0,s = 0,b = INT_MIN;
    }
};

class SegTree
{
	vector<node> tree;
    int n;
    public:
	    SegTree(vector<int> &nums)
	    {
	        n = nums.size();
	        tree.resize(4*n);
	        buildSegTree(nums,1,0,n-1);
	    }
	    node query(node &ans,int i,int j)
	    {
	        return querySegTree(ans,1,0,n-1,i,j);
	    }
	
	    node merge(node a,node b)
	    {
	        node ans;
	        ans.s = a.s+b.s;
	        ans.l = max(a.l,a.s+b.l);
	        ans.r = max(b.r,b.s+a.r);
	        ans.b = max(max(a.b,b.b),a.r+b.l);
	        return ans;
	    }
	
	    void buildSegTree(vector<int> &nums,int treeIndex,int lo,int hi)
	    {
	        if(lo==hi)
	        {
	            tree[treeIndex].l = tree[treeIndex].r = tree[treeIndex].s = tree[treeIndex].b = nums[lo];
	            return;
	        }
	        int mid = lo + (hi-lo)/2;
	        buildSegTree(nums,2*treeIndex,lo,mid);
	        buildSegTree(nums,2*treeIndex+1,mid+1,hi);
	
	        tree[treeIndex] = merge(tree[2*treeIndex],tree[2*treeIndex+1]);
	    }
	
	    node querySegTree(node &ans,int treeIndex,int lo,int hi,int i,int j)
	    {
	        if(i==lo && j==hi) return tree[treeIndex];
	        int mid = lo + (hi-lo)/2;
	        if(i>mid) return querySegTree(ans,2*treeIndex+1,mid+1,hi,i,j);
	        else if(j<=mid) return querySegTree(ans,2*treeIndex,lo,mid,i,j);
	        
	        node leftQuery,rightQuery;
	        leftQuery = querySegTree(leftQuery,2*treeIndex,lo,mid,i,mid);
	        rightQuery = querySegTree(rightQuery,2*treeIndex+1,mid+1,hi,mid+1,j);
	
	        return merge(leftQuery,rightQuery);
	    }
};

int32_t main()
{
    IOS;
    int n,m;
    cin>>n;
    vector<int> nums(n);
    FOR(i,0,n) cin>>nums[i];
    SegTree st(nums);
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        node ans;
        ans = st.query(ans,x,y);
        cout<<ans.b<<"\n";
    }
    return 0;
}