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
const int N = 12;
vector<int>arr(N);
ll dp[N][N];
int n, m;
ll rec(int last_digit, int len){
	if(len == m)
		return 1;
	if(dp[last_digit][len] != -1)
		return dp[last_digit][len];

	ll ans = 0;
	for(int i = 0; i < n; i++){

		if(abs(last_digit - arr[i]) <= 2 || last_digit == 0)
			ans += rec(arr[i], len + 1);

	}
	return dp[last_digit][len] = ans;
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
    	cin >> n >> m;

    	memset(dp, 0, sizeof dp);
    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    		dp[arr[i]][1] = 1;
    	}

    
    	for(int len = 2; len <= m; len++){
    		for(int i = 0; i < n; i++){
    			for(int j = 0; j < n; j++){
    				if(abs(arr[i] - arr[j]) <= 2){
    					dp[arr[j]][len] += dp[arr[i]][len - 1]; 
    				}
    			}
    		}
    	}

    	debug(dp);

    	ll ans = 0;
    	for(int i = 0; i < n; i++){
    		ans += dp[arr[i]][m];
    	}

    	cout << "Case " << ++cs << ": " << ans << endl;

    }
    return 0 ;

    runtime();

}
