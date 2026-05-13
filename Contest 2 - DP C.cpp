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
const int N = 1e5 + 7;
int n;
ll dp[N][5];
ll arr[N][5];
ll solve(int i, int k){
	if(i == n)
		return 0;


	if(dp[i][k] != -1)
		return dp[i][k];
	ll ans = 0;

	for(int j = 1; j <= 3; j++){

		if(j == k)
			continue;

		ans = max(ans, solve(i + 1, j) + arr[i][j]);
	}



	return dp[i][k] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

    cin >> n;

    for(int i = 1; i <= n; i++){
    	cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    for(int i = 1; i <= n; i++){
    	for(int k = 1; k <= 3; k++){
    		for(int j = 1; j <= 3; j++){
    			if(k == j && i != 1)
    				continue;
    			dp[i][j] = max(dp[i - 1][k] + arr[i][j], dp[i][j]);
    		}
    	}
    }

    cout <<  max({dp[n][1], dp[n][2],dp[n][3]})<< endl;

    debug(dp);
    return 0 ;

    runtime();

}
