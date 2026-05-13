#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
const int mod = 1e9 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int n , m;
    cin >> n >> m;
    vector<vector<ll>>dp(n + 2, vector<ll>(m + 2, 0));
    vector<int>arr(n + 1);

    for(int i = 1; i <= n; i++){
    	cin >> arr[i];
    }

    for(int i = 1; i <= m; i++){
    	dp[1][i] = (arr[1] == 0 || arr[1] == i);
    }

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		if(arr[i] == 0 || arr[i] == j){
    			for(int k = -1; k <= 1; k++){
    				dp[i][j] += dp[i - 1][j + k];
    				dp[i][j] %= mod;
    			}
    		}
    	}
    }

    ll ans = 0;

    for(int i = 1; i <= m; i++){
    	ans += dp[n][i];
    	ans %= mod;
    }

    debug(dp);

    cout << ans << endl;


    return 0 ;

    runtime();

}
