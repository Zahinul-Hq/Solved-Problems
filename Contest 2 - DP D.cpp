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
const int mod= 100000007, N = 105, K = 1e4 + 7;
int n, k;
vector<int>arr(N, 0);
ll dp[N][K];

int solve(int i, int sum){
	if(i == n ){
		if(sum == 0){
			return 1;
		}
		return 0;
	}

	if(dp[i][sum] != -1)
		return dp[i][sum];


	int ans = solve(i + 1, sum) % mod;

	if(sum - arr[i] >= 0)
		ans += (solve(i, sum - arr[i]) % mod);



	return  ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases, cs = 0 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	cin >> n >> k;

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}

    	for(int i = 0; i <= n; i++){
    		for(int j = 0; j <= k; j++){
    			dp[i][j] = -1;
    		}
    	}
    	vector<int>pp;

    	cout << "Case " << ++cs << ": ";

    	cout << solve(0, k) << endl;

    	//debug(dp);
    }
    return 0 ;

    runtime();

}
