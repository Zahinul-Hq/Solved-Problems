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
const int N = 1e5 ;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int coins[5], times[5], q, v;

    	cin >> coins[1] >> coins[2] >> coins[3] >> coins[4] >> q;
    	ll dp[N];
	    memset(dp, 0, sizeof dp);
	    dp[0] = 1;

	    for(int i = 1; i <= 4; i++){
	    	for(int j = coins[i]; j < N; j++){
	    		dp[j] += dp[j - coins[i]];
	    	}
	    }

	    

    	while(q--){
    		
    		cin >> times[1] >> times[2] >> times[3] >> times[4] >> v;
	    	ll res = 0;
    		for(int i = 0; i < (1 << 4); i++){
    			ll rem = v;
    			for(int j = 0; j < 4; j++){
    				if(i & (1 << j)){
    					rem  -= (1LL * (times[j + 1] + 1) * coins[j + 1]);
    				}
    			}

    			if(rem >= 0){
    				if(__builtin_popcount(i) % 2 == 1){
    					res -= dp[rem];
    				}else{
    					res += dp[rem];
    				}

    			}

    			
    		}
    		cout << res << endl;
	    	
    	}
    	
    }
    return 0 ;

    runtime();

}
