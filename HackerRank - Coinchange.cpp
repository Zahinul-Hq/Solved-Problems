#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e10

const int N = 2e7 + 5;
ll dp[55][300];
vector<int>arr(55, 0);
int n, m ;


ll func(ll i, ll sum)
{
    if(i == m || sum <= 0){
        if(sum == 0){
            return 1;
        }

        return 0;

    }

    if(dp[i][sum] != -1)
        return dp[i][sum];

    ll ans = func(i + 1, sum);
    
    ans += func(i , sum - arr[i]);


    return dp[i][sum] = ans;

}
int main()
{

    memset(dp, -1, sizeof dp);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> arr[i];
    }

    cout << func(0, n) << endl;
}