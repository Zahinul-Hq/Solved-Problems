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
const int N = 205;
ll n, m, k;
ll arr[N][N];
ll dp[N][N][N], mn[N][N];

ll solve(int i, int j, int s){
	//debug(i, j);
	if(i == n - 1  ){

		ll mnn = inf;

		for(ll p = 0; p < m; p++){
			ll val = 0;
			for(int l = j; l < m; l++){

				val += (arr[i][(l + s +p) % m]);

			}
			mnn = min(val + (k * p), mnn);
		}
		return mnn;
		
	}

	if(dp[i][j][s] != -1)
		return dp[i][j][s];

	ll ans = inf;
	
	for(ll p = 0; p  < m; p++){
		if(i + 1 <= n){
			ans = min(ans, solve(i + 1, j, (p + s) % m) + ( p * k) + arr[i][(p + j + s) % m] );
		}
				
	}
	for(ll p = 0; p  < m; p++){
		if(j + 1 <= m){
			ans = min(ans, solve(i , j + 1, (p + s) % m)+ (p * k) + arr[i][(s + j + p) % m]);
		}		
	}
	//debug(i, j, ans);
	
	return dp[i][j][s] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	cin >> n >> m >> k;

    	for(int i = 0; i <= n + 1; i++){
    		for(int j = 0; j <= m + 1; j++){
    			for(int l = 0; l <= m + 1; l++)
    				dp[i][j][l] = inf;
    			mn[i][j] = inf;
    		}
    	}
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < m; j++){
    			cin >> arr[i][j];
    		}
    	}
    	for(int i = 0; i < m; i++){
    		dp[0][0][i] = arr[0][i];
    	}
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < m; j++){
    			for(int s = 0; s < m; s++){
    				if(!i || !j)
    					continue;
    				dp[i][j][s] = min(dp[i][j][s], mn[i - 1][j])
    			}
    		}
    	}
    	

    	

    	cout << solve(0, 0, 0) << endl;
    	//debug(dp);


    }
    return 0 ;

    runtime();

}
