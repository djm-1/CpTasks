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



bool predicate(int p, int t, vector<int>&arr, int l){
    int paratha=0;
    for(int i=0;i<l;i++)
    {
        for(int k=p;k>=0;k--)
        {
            if((k*(k+1))/2<=t/arr[i])
            {
                paratha+=k;
                break;
            }
        }
    }
    if(paratha<p)
        return false;
    return true;
}

void solve(){
    int p,l;
    cin>>p>>l;
    vector<int>arr(l);
    for(int i=0;i<l;i++)
        cin>>arr[i];

    int left=1;
    int right=(p*(p+1))/2*(*max_element(arr.begin(),arr.end()));

    while(left<right){
        int mid=left+(right-left)/2;
        if(predicate(p,mid,arr,l))
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    cout<<left<<"\n";
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
