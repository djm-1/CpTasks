
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;
ll inf=INT_MAX;
 

ll cnt=0;

int main(){
    int n,m,x,y;
    cin>>n>>m;
    vector<int>adj[n+1],backedge[n+1];
    vector<int>indegree(n+1,0),dp(n+1,0);


    dp[1]=1;
    while(m--)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
        backedge[y].push_back(x);
    }

    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty())
    {
        int v=q.front();
        q.pop();

        for(auto x:adj[v])
        {
            indegree[x]--;
            if(indegree[x]==0)
                q.push(x);
        }

        for(auto x:backedge[v])
        {
            dp[v]=(dp[v]+dp[x])%mod;
        }        
    }

    cout<<dp[n]%mod;
}
