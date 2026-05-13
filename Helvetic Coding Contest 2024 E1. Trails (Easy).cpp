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

    int m, n;
    cin >> m >> n;

    vector<ll>s(m + 1), l(m + 1);
    for(int i = 1; i <= m; i++){
    	cin >> s[i];
    }
    for(int i = 1; i <= m; i++){
    	cin >> l[i];
    }
    ll dp[n + 1][m + 1] = {};

    dp[0][1] =1;

    for(int k = 1; k <= n; k++){
    	for(int i = 1; i <= m; i++){
    		ll ti = s[i] + l[i];
    		for(int j = 1; j <= m; j++){
    			ll tj = s[j] + l[j];
    			dp[k][i] = ((dp[k][i] % mod)  + (((((ti * tj) - (l[i] * l[j])) % mod) * (dp[k - 1][j] % mod)) % mod)) % mod;
    		}
    	}
    }
    ll ans = 0;

    for(int i = 1; i <= m; i++){
    	ans += dp[n][i];
    	ans %= mod;
    }

    cout << ans << endl;
    return 0 ;

    runtime();

}
