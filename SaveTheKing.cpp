
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;
ll inf=INT_MAX;
 
vector<ll>rankk,parent;
 
ll find(ll v)
{
    if(parent[v]==v)
        return v;
    return parent[v]=find(parent[v]);
}
 
 
bool union_find(ll u, ll v)
{
    ll a=find(u);
    ll b=find(v);
 
    if(a==b)
        return false;
 
    if(rankk[b]>rankk[a])
        swap(a,b);
    if(rankk[a]==rankk[b])
        rankk[a]++;
 
    parent[b]=a;
    return true;
}
 
void solve(){
        ll m,n,u,v,w;
    cin>>n>>m;
    parent.resize(n+1);
    rankk.resize(n+1);
 
    for(ll i=1;i<=n;i++)
    {
        rankk[i]=0;
        parent[i]=i;
    }
 
 
    vector<pair<ll,pair<ll,ll>>>edges;
 
    while(m--)
    {
        cin>>u>>v>>w;
 
        edges.push_back({w,{u,v}});
    }
 
    sort(edges.begin(),edges.end());
 
    ll cost=0;
    for(auto x:edges)
    {
        u=x.second.first;
        v=x.second.second;
        w=x.first;
 
        if(union_find(u,v))
        {
            cost+=log2(w);
        }
    }
    cout<<cost+1<<"\n"; 
} 
 
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
