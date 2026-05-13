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
const int sz  = 55;

int n;

// ll dp(int l , int r, vector<ll>&arr){
// 	if(l + 1 >= r){
// 		return 0;
// 	}
// 	if(memo[l][r] != -1){
// 		return memo[l][r];
// 	}

// 	ll ans = inf;

// 	for(int mid = l + 1 ; mid < r; mid++){
// 		ans = min(ans, dp(l, mid,arr) + (arr[r]- arr[l]) + dp(mid  , r, arr));
// 	}
// 	return memo[l][r] = ans;
// }
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int len;
    
    while (cin >> len && len)
    {
    	cin >> n;
    	vector<ll>arr(n + 2, 0);
    	vector<vector<ll>>dp(n + 2, vector<ll>( n + 2, inf));

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}
    	for(int l = 0; l <= n ; l++){
    		dp[l][l] = dp[l][l + 1] = 0;
    	}
    	dp[n + 1][n + 1] = 0;

    	arr[0] = 0;
    	arr[n + 1] = len;

		sort(arr.begin(), arr.end());
    	for(int l = 2; l <= n + 1; l++){
    		for(int i = 0; l + i <= n + 1; i++){
    			int j = i + l;
    			for(int mid = i + 1; mid < j; mid++){

    				dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid][j] + arr[j] - arr[i]);

    			}
    		}
    	}


    	cout << "The minimum cutting is " << dp[0][n + 1] << "." << endl;
    }
    return 0 ;

    runtime();

}
