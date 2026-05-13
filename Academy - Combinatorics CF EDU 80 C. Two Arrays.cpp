#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N = 1005, mod = 1e9 + 7;
int n, m;

ll dp[11][N];

ll solve(int i, int last_value){
	if(i == 0){
		return 1;
	}

	if(dp[i][last_value] != -1)
		return dp[i][last_value];

	ll ans = 0;

	for(int val = last_value; val >= 1; val--){
		ans += solve(i - 1, val);
		ans %= mod;
	}

	return dp[i][last_value] = ans % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

	
    cin >> n >> m;

    memset(dp, -1, sizeof dp);
    
    ll ans = solve(m,n) % mod;	

    ll total_ans = 0;

    if(m == 1){

    	for(int i = 1; i <= n; i++){
    		total_ans += (ans--);
    		total_ans %= mod;
    	}
    	cout << total_ans << endl;
    	return 0;
    }
    

   	for(int i = 1; i <= n; i++){

   		ll cnt = dp[m - 1][n - i + 1];
   		total_ans += ((dp[m - 1][i] % mod) * (ans % mod));
   		total_ans %= mod;
   		ans = (ans + mod - cnt) % mod;	
   	}

   	cout << total_ans << endl;
    return 0 ;
}
