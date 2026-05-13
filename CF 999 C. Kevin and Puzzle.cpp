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
const int mod = 998244353;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;
    	vector<int>arr(n + 1);
    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}


    	vector<ll>dp(n + 1, 0);
    	dp[0] = 1, dp[1] = arr[1] == 0;


    	for(int i = 2; i <= n; i++){
    		for(int l = 0; l < 2; l++){
    			if(l == 0){
    				if(i > 1 && arr[i - 2] + 1 == arr[i]){
    					dp[i] += dp[i - 2];
    					dp[i] %= mod;
    				}
    			}else{
    				if(arr[i - 1] == arr[i]){
    					dp[i] += dp[i - 1];
    					dp[i] %= mod;
    				}

    			}
    		}
    	}

    	cout << (dp[n] + dp[n - 1]) % mod << endl;


    }
    return 0 ;

    runtime();

}
