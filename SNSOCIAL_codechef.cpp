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


void solve()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    int maxi=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]>maxi){
                maxi=arr[i][j];
            }
        }
    }


    queue<pair<int,int>>Q;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==maxi)
            {
                Q.push({i,j});
            }
        }
    }


    vector<vector<int>>dir={
        {-1,0},
        {1,0},
        {0,1},
        {0,-1},
        {1,1},
        {1,-1},
        {-1,1},
        {-1,-1}
    };
    int level=0;
    while(!Q.empty()){
            int sz=Q.size();
            for(int i=0;i<sz;i++){
            auto v=Q.front();
            Q.pop();
            for(int d=0;d<8;d++)
            {
                int x=v.first+dir[d][0];
                int y=v.second+dir[d][1];

                if(x>=0 && x<n && y>=0 && y<m && arr[x][y]<arr[v.first][v.second])
                {
                    arr[x][y]=arr[v.first][v.second];
                    Q.push({x,y});
                }
            }
        }
        level++;
    }

    cout<<level-1<<"\n";
}


int main()
{
    ///fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        int t;
        cin>>t;
        while(t--)
        {
            solve();
        }

}
