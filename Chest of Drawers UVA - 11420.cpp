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

// ll rec(int len, bool locked, int sum){
// 	if(len == n){
// 		if(sum == s)
// 			return 1;
// 		return 0;
// 	}
// 	if(dp[len][locked][sum] != -1)
// 		return dp[len][locked][sum];

// 	ll ans = 0;
// 	ans += rec(len + 1, locked ^ 1, sum);
// 	ans += rec(len + 1, locked, sum + locked);

// 	return dp[len][locked][sum] = ans;
// }
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
    ll dp[67][2][67];
    ll n, s;
    memset(dp, 0, sizeof dp);

    dp[0][1][0] = 1;

    for(int len = 0; len <= 65; len++){
        for(int locked = 0; locked < 2; locked++){
            for(int sum = 0; sum <= 65; sum++){
                dp[len + 1][locked ^ 1][sum] += dp[len][locked][sum];
                if(sum + locked <= 65){
                    dp[len + 1][locked][sum + locked] += dp[len][locked][sum];
                }
            }
        }
    }
    while ((cin >> n >> s)){

        if(n < 0 && s < 0 )
            break;

        cout << (dp[n][0][s] + dp[n][1][s]) << endl;
    }
    return 0 ;

    runtime();

}
