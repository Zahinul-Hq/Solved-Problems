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
const int N = 5005;
int grid[2][N];

ll dp[N][2];
int n;
ll solve(int i, bool t){

	if(i == n ){
		if(t == 0)
			return 0;
		return low;
	}

	if(dp[i][t] != -1)
		return dp[i][t];

	ll ans = low;

	ans = max(ans, solve(i + 1, t) + grid[0][i]);

	ans = max(ans, solve(i + 1, t) + grid[1][i]);

	if(t){
		ans = max(ans, solve(i + 1, 0) + grid[1][i] + grid[0][i]);
	}

	return dp[i][t] = ans;
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
    	cin >> n;

    	for(int i = 0; i < n; i++){
    		cin >> grid[0][i];
    	}
    	for(int i = 0; i < n; i++){
    		cin >> grid[1][i];
    	}
    	for(int i = 0; i <= n; i++){
    		dp[i][1] = dp[i][0] = -1;
    	}

    	cout << solve(0, 1) << endl;

    }
    return 0 ;

    runtime();

}
