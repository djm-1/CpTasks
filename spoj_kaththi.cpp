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


void solve(){
    int r,c;
    cin>>r>>c;
    char arr[r][c];
    

    for(int i=0;i<r;i++)
    {    
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }    

    vector<vector<int>>dir={
        {-1,0},
        {1,0},
        {0,1},
        {0,-1}
    };

    
    deque<pair<int,int>>Q;
    vector<vector<int>>dist(r,vector<int>(c,INT_MAX));

    dist[0][0]=0;
    Q.push_back({0,0});

    while(!Q.empty()){
        auto v=Q.front();
        Q.pop_front();
        for(int k=0;k<4;k++)
        {
            int x=v.first+dir[k][0];
            int y=v.second+dir[k][1];

            if(x>=0 && x<r && y>=0 && y<c){
                int wt=arr[v.first][v.second]==arr[x][y]?0:1;
                if(dist[v.first][v.second]+wt<dist[x][y]){
                    dist[x][y]=dist[v.first][v.second]+wt;
                    if(wt==0)
                    {
                        Q.push_front({x,y});
                    }
                    else
                    {
                        Q.push_back({x,y});
                    }
                }
            }
        }
    }
    
    cout<<dist[r-1][c-1]<<"\n";
}



int main()
{
    ///fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

}
