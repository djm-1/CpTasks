#include <bits/stdc++.h>
using namespace std;
#define INF 1e5+7
int main() {
	// your code goes here
	int n,m,x,y;
	cin>>n>>m;
	vector<vector<pair<int,int>>>adj(n+1);
	while(m--)
	{
	    cin>>x>>y;
	    adj[x].push_back({0,y});
	    adj[y].push_back({1,x});
	}
	
	vector<int>level(n+1,INF);
	level[1]=0;
	
	deque<int>Q;
	Q.push_back(1);
	
	while(!Q.empty()){
	    int v=Q.front();
	    Q.pop_front();
	    for(auto x:adj[v])
	    {
	        int wt=x.first;
	        int node=x.second;
	        
	        if(level[v]+wt<level[node]){
	            level[node]=level[v]+wt;
	            if(wt==0){
	                Q.push_front(node);
	            }
	            else
	            {
	                Q.push_back(node);
	            }
	        }
	    }
	}
	
	if(level[n]==INF)
	    cout<<-1;
	else
	    cout<<level[n];
	
	return 0;
}
