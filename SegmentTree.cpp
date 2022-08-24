/*

    ******          *********        ***     ***
    *******         *********        ****   ****
    **    ***              **        ** ** ** **
    **     ***             **        **  ***  **
    **    ***       **     **        **   *   **
    *******          ********        **       **
    ******            *******        **       **




/*******Author:djm_boss*******/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;
ll inf=INT_MAX;

class SegmentTree{
public:
    vector<ll>st;

    void init(ll n){
        st.resize(4*n,0);
    }

    void buildTree(ll start, ll end, ll node, vector<ll>&arr)
    {
        if(start==end){
            st[node]=arr[start];
            return;
        }

        ll mid=(start+end)/2;
        buildTree(start,mid,2*node+1,arr);
        buildTree(mid+1,end,2*node+2,arr);

        st[node]=st[2*node+1]+st[2*node+2];
        
    }


    ll query(ll start, ll end, ll l, ll r,ll node)
    {
        // no overlap
        if(start>r||end<l)
            return 0;

        // complete overlap
        if(start>=l && end<=r)
            return st[node];

        // partial overlap
        ll mid=(start+end)/2;
        ll q1=query(start,mid,l,r,2*node+1);
        ll q2=query(mid+1,end,l,r,2*node+2);
        return q1+q2;
    }

    void update(ll start,ll end, ll index, ll node,ll val)
    {
        if(index>end||index<start)
            return;
        if(start==end)
        {
            st[node]=val;
            return;
        }

        ll mid=(start+end)/2;

        if(index<=mid)
        {
            update(start,mid,index,2*node+1,val);
        }
        else
        {
            update(mid+1,end,index,2*node+2,val);
        }

        st[node]=st[2*node+1]+st[2*node+2];
    }
};



int main()
{
    ///fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;

    vector<ll>arr(n);
    
    for(ll i=0;i<n;i++)
        cin>>arr[i];

    SegmentTree Tree;
    Tree.init(n);

    Tree.buildTree(0,n-1,0,arr);

    ll t,u,v;
    while(m--)
    {
        cin>>t>>u>>v;
        if(t==1)
        {
            Tree.update(0,n-1,u,0,v);
        }
        else
        {
            cout<<Tree.query(0,n-1,u,v-1,0)<<"\n";
        }
    }
}

